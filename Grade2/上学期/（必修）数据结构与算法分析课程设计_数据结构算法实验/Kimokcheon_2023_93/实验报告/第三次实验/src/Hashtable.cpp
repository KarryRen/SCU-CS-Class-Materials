#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

class HashTable {
    static const int HASH_GROUPS = 10; // 哈希表大小
    std::vector<std::list<int>> table; // 使用链表解决冲突

public:
    HashTable() : table(HASH_GROUPS) {}

    // 计算哈希函数
    int hashFunction(int key) {
        return key % HASH_GROUPS;
    }

    // 插入键值对
    void insertItem(int key, int value) {
        int index = hashFunction(key);
        table[index].push_back(value);
    }

    // 删除键值对
    void deleteItem(int key, int value) {
        int index = hashFunction(key);
        table[index].remove(value);
    }

    // 查找键值对
    bool searchItem(int key, int value) {
        int index = hashFunction(key);
        return std::find(table[index].begin(), table[index].end(), value) != table[index].end();
    }

    // 打印哈希表
    void printTable() {
        for (int i = 0; i < HASH_GROUPS; ++i) {
            std::cout << "Group " << i << ": ";
            for (const auto& item : table[i]) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
};

void runTests() {
    HashTable hashTable;

    // 测试用例组1: 插入和搜索
    std::cout << "Test 1: Insert and Search" << std::endl;
    hashTable.insertItem(1, 10);
    hashTable.insertItem(11, 20);
    hashTable.insertItem(21, 30);
    std::cout << "Expected: Found. Actual: " << (hashTable.searchItem(11, 20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Expected: Not Found. Actual: " << (hashTable.searchItem(12, 20) ? "Found" : "Not Found") << std::endl;

    // 测试用例组2: 插入和删除
    std::cout << "\nTest 2: Insert and Delete" << std::endl;
    hashTable.deleteItem(11, 20);
    std::cout << "Expected: Not Found. Actual: " << (hashTable.searchItem(11, 20) ? "Found" : "Not Found") << std::endl;

    // 测试用例组3: 多次插入和删除
    std::cout << "\nTest 3: Multiple Insert and Delete" << std::endl;
    hashTable.insertItem(11, 40);
    std::cout << "Expected: Found. Actual: " << (hashTable.searchItem(11, 40) ? "Found" : "Not Found") << std::endl;

    // 测试用例组4: 空哈希表的搜索和删除
    std::cout << "\nTest 4: Empty Table" << std::endl;
    hashTable = HashTable();  // Reset hash table
    std::cout << "Expected: Not Found. Actual: " << (hashTable.searchItem(1, 10) ? "Found" : "Not Found") << std::endl;

    // 测试用例组5: 处理冲突
    std::cout << "\nTest 5: Handle Collisions" << std::endl;
    hashTable.insertItem(1, 10);
    hashTable.insertItem(11, 20);
    std::cout << "Expected: Found. Actual: " << (hashTable.searchItem(1, 10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Expected: Found. Actual: " << (hashTable.searchItem(11, 20) ? "Found" : "Not Found") << std::endl;
}

int main() {
    runTests();
    return 0;
}