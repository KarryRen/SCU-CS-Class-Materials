//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_k_replacer.cpp
//
// Identification: src/buffer/lru_k_replacer.cpp
//
// Copyright (c) 2015-2022, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_k_replacer.h"

namespace bustub {

// 构造函数，初始化LRUKReplacer
LRUKReplacer::LRUKReplacer(size_t num_frames, size_t k) : replacer_size_(num_frames), k_(k) {
  history_queue = std::unordered_map<frame_id_t, std::list<size_t>>();
  last_accesed_queue = std::unordered_map<frame_id_t, size_t>();
}

// 驱逐一个页面框架
auto LRUKReplacer::Evict(frame_id_t *frame_id) -> bool {
  std::lock_guard<std::mutex> lock(latch_);
  *frame_id = -1;
  current_timestamp_++;
  
  // 如果历史队列和最近访问队列都为空，则无法驱逐
  if (history_queue.empty() && last_accesed_queue.empty()) {
    return false;
  }
  
  size_t last_recently_usedts = current_timestamp_;
  
  // 遍历历史队列，找到最久未使用的可驱逐页面框架
  for (const auto &kv_pair : history_queue) {
    if (is_evictable.find(kv_pair.first) != is_evictable.end() && kv_pair.second.front() < last_recently_usedts) {
      *frame_id = kv_pair.first;
      last_recently_usedts = kv_pair.second.front();
    }
  }

  // 如果在历史队列中找到可驱逐的页面框架，则移除它
  if (history_queue.find(*frame_id) != history_queue.end()) {
    history_queue.erase(*frame_id);
    is_evictable.erase(*frame_id);
    return true;
  }

  // 遍历最近访问队列，找到最久未使用的可驱逐页面框架
  for (const auto &kv_pair : last_accesed_queue) {
    if (is_evictable.find(kv_pair.first) != is_evictable.end() && kv_pair.second < last_recently_usedts) {
      *frame_id = kv_pair.first;
      last_recently_usedts = kv_pair.second;
    }
  }
  
  // 如果没有找到可驱逐的页面框架，则返回false
  if (*frame_id == -1) {
    return false;
  }
  
  // 从最近访问队列中移除找到的页面框架
  last_accesed_queue.erase(*frame_id);
  is_evictable.erase(*frame_id);
  return true;
}

// 记录页面框架的访问
void LRUKReplacer::RecordAccess(frame_id_t frame_id) {
  std::lock_guard<std::mutex> lock(latch_);
  current_timestamp_++;
  
  // 如果页面框架ID超出范围，则返回
  if (frame_id >= static_cast<int>(replacer_size_)) {
    return;
  }
  
  // 如果页面框架在最近访问队列中，则更新其访问时间戳
  if (last_accesed_queue.find(frame_id) != last_accesed_queue.end()) {
    last_accesed_queue[frame_id] = current_timestamp_;
    return;
  }
  
  // 如果页面框架不在历史队列中，则将其加入历史队列
  if (history_queue.find(frame_id) == history_queue.end()) {
    history_queue[frame_id] = std::list<size_t>();
  }

  history_queue[frame_id].push_back(current_timestamp_);

  // 如果页面框架的访问次数达到k次，则将其移到最近访问队列
  if (history_queue[frame_id].size() >= k_) {
    last_accesed_queue[frame_id] = current_timestamp_;
    history_queue.erase(frame_id);
  }
}

// 设置页面框架是否可被驱逐
void LRUKReplacer::SetEvictable(frame_id_t frame_id, bool set_evictable) {
  std::lock_guard<std::mutex> lock(latch_);
  current_timestamp_++;
  
  // 如果页面框架不在历史队列和最近访问队列中，则返回
  if (set_evictable && history_queue.find(frame_id) == history_queue.end() &&
      last_accesed_queue.find(frame_id) == last_accesed_queue.end()) {
    return;
  }
  
  // 设置页面框架的可驱逐状态
  if (set_evictable) {
    is_evictable[frame_id] = true;
  } else {
    is_evictable.erase(frame_id);
  }
}

// 移除页面框架
void LRUKReplacer::Remove(frame_id_t frame_id) {
  std::lock_guard<std::mutex> lock(latch_);
  current_timestamp_++;
  
  // 从所有队列中移除页面框架
  history_queue.erase(frame_id);
  last_accesed_queue.erase(frame_id);
  is_evictable.erase(frame_id);
}

// 获取可驱逐页面框架的数量
auto LRUKReplacer::Size() -> size_t {
  std::lock_guard<std::mutex> lock(latch_);
  return is_evictable.size();
}
}  // namespace bustub
