#include <iostream>
#include <vector>

// 顺序查找函数
int SequentialSearch(const std::vector<int>& arr, int value) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) return static_cast<int>(i); // 返回找到的索引
    }
    return -1; // 未找到返回-1
}

// 二分查找函数
int BinarySearch(const std::vector<int>& arr, int value) {
    if (arr.empty()) return -1; // 空数组时直接返回-1

    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) return mid; // 找到值
        else if (arr[mid] < value) low = mid + 1; // 调整查找范围
        else high = mid - 1;
    }
    return -1; // 未找到
}

void RunTests() {
    // 测试顺序查找
    std::vector<int> arr1 = {10, 20, 30, 40, 50};
    std::cout << "Sequential Search Test 1 (Find 30): " << (SequentialSearch(arr1, 30) != -1 ? "Passed" : "Failed") << std::endl;
    std::cout << "Sequential Search Test 2 (Find 100): " << (SequentialSearch(arr1, 100) == -1 ? "Passed" : "Failed") << std::endl;

    std::vector<int> arr2 = {};
    std::cout << "Sequential Search Test 3 (Empty Array): " << (SequentialSearch(arr2, 10) == -1 ? "Passed" : "Failed") << std::endl;

    std::vector<int> arr3 = {5};
    std::cout << "Sequential Search Test 4 (Single Element, Found): " << (SequentialSearch(arr3, 5) != -1 ? "Passed" : "Failed") << std::endl;
    std::cout << "Sequential Search Test 5 (Single Element, Not Found): " << (SequentialSearch(arr3, 10) == -1 ? "Passed" : "Failed") << std::endl;

    // 测试二分查找
    std::vector<int> arr4 = {1, 2, 3, 4, 5, 6};
    std::cout << "Binary Search Test 1 (Find 1): " << (BinarySearch(arr4, 1) != -1 ? "Passed" : "Failed") << std::endl;
    std::cout << "Binary Search Test 2 (Find 6): " << (BinarySearch(arr4, 6) != -1 ? "Passed" : "Failed") << std::endl;
    std::cout << "Binary Search Test 3 (Find 7): " << (BinarySearch(arr4, 7) == -1 ? "Passed" : "Failed") << std::endl;

    std::vector<int> arr5 = {};
    std::cout << "Binary Search Test 4 (Empty Array): " << (BinarySearch(arr5, 10) == -1 ? "Passed" : "Failed") << std::endl;

    std::vector<int> arr6 = {7};
    std::cout << "Binary Search Test 5 (Single Element, Found): " << (BinarySearch(arr6, 7) != -1 ? "Passed" : "Failed") << std::endl;
    std::cout << "Binary Search Test 6 (Single Element, Not Found): " << (BinarySearch(arr6, 8) == -1 ? "Passed" : "Failed") << std::endl;
}

int main() {
    RunTests();
    return 0;
}
