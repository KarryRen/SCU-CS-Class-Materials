//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// extendible_hash_table.cpp
//
// Identification: src/container/hash/extendible_hash_table.cpp
//
// Copyright (c) 2022, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include <cassert>
#include <cstdlib>
#include <functional>
#include <list>
#include <utility>

#include "container/hash/extendible_hash_table.h"
#include "storage/page/page.h"

namespace bustub {

template <typename K, typename V>
ExtendibleHashTable<K, V>::ExtendibleHashTable(size_t bucket_size) : bucket_size_(bucket_size) {
  dir_.push_back(std::make_shared<Bucket>(bucket_size, 0));
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::IndexOf(const K &key) -> size_t {
  int mask = (1 << global_depth_) - 1;
  return std::hash<K>()(key) & mask;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetGlobalDepth() const -> int {
  std::scoped_lock<std::mutex> lock(latch_);
  return GetGlobalDepthInternal();
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetGlobalDepthInternal() const -> int {
  return global_depth_;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetLocalDepth(int dir_index) const -> int {
  std::scoped_lock<std::mutex> lock(latch_);
  return GetLocalDepthInternal(dir_index);
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetLocalDepthInternal(int dir_index) const -> int {
  return dir_[dir_index]->GetDepth();
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetNumBuckets() const -> int {
  std::scoped_lock<std::mutex> lock(latch_);
  return GetNumBucketsInternal();
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::GetNumBucketsInternal() const -> int {
  return num_buckets_;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Find(const K &key, V &value) -> bool {
  std::scoped_lock<std::mutex> lock(latch_);
  auto index = IndexOf(key);
  auto bucket = dir_[index];
  return bucket->Find(key, value);
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Remove(const K &key) -> bool {
  std::scoped_lock<std::mutex> lock(latch_);
  auto index = IndexOf(key);
  auto bucket = dir_[index];
  return bucket->Remove(key);
}

template <typename K, typename V>
void ExtendibleHashTable<K, V>::Insert(const K &key, const V &value) {
  std::scoped_lock<std::mutex> lock(latch_);

  while (dir_[IndexOf(key)]->IsFull()) {
    auto idx = IndexOf(key);
    auto bucket = dir_[idx];

    if (bucket->GetDepth() == GetGlobalDepthInternal()) {
      global_depth_++;
      int old_size = dir_.size();
      dir_.resize(old_size << 1);
      for (int i = 0; i < old_size; i++) {
        dir_[i + old_size] = dir_[i];
      }
    }

    int depth_mask = 1 << bucket->GetDepth();
    auto new_bucket_0 = std::make_shared<Bucket>(bucket_size_, bucket->GetDepth() + 1);
    auto new_bucket_1 = std::make_shared<Bucket>(bucket_size_, bucket->GetDepth() + 1);

    for (const auto &item : bucket->GetItems()) {
      size_t hash_key = std::hash<K>()(item.first);
      if ((hash_key & depth_mask) != 0U) {
        new_bucket_1->Insert(item.first, item.second);
      } else {
        new_bucket_0->Insert(item.first, item.second);
      }
    }

    num_buckets_++;

    for (size_t i = 0; i < dir_.size(); i++) {
      if (dir_[i] == bucket) {
        if ((i & depth_mask) != 0U) {
          dir_[i] = new_bucket_1;
        } else {
          dir_[i] = new_bucket_0;
        }
      }
    }
  }

  auto idx = IndexOf(key);
  auto bucket = dir_[idx];

  for (auto &item : bucket->GetItems()) {
    if (item.first == key) {
      item.second = value;
      return;
    }
  }

  bucket->Insert(key, value);
}

//===--------------------------------------------------------------------===//
// Bucket
//===--------------------------------------------------------------------===//
template <typename K, typename V>
ExtendibleHashTable<K, V>::Bucket::Bucket(size_t array_size, int depth) : size_(array_size), depth_(depth) {}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Find(const K &key, V &value) -> bool {
  bool found = false;
  for (const auto &item : list_) {
    if (item.first == key) {
      value = item.second;
      found = true;
      break;
    }
  }
  return found;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Remove(const K &key) -> bool {
  bool removed = false;
  for (const auto &item : list_) {
    if (item.first == key) {
      list_.remove(item);
      removed = true;
      break;
    }
  }
  return removed;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Insert(const K &key, const V &value) -> bool {
  bool inserted = false;
  if (list_.size() < size_) {
    list_.push_back(std::make_pair(key, value));
    inserted = true;
  }
  return inserted;
}

template class ExtendibleHashTable<page_id_t, Page *>;
template class ExtendibleHashTable<Page *, std::list<Page *>::iterator>;
template class ExtendibleHashTable<int, int>;
// test purpose
template class ExtendibleHashTable<int, std::string>;
template class ExtendibleHashTable<int, std::list<int>::iterator>;

}  // namespace bustub
