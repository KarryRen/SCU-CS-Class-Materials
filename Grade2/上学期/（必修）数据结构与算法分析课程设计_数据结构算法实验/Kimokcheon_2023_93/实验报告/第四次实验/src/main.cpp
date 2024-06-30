#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;

// 打印数组的函数
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


// 折半插入排序
void binaryInsertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i]; // 当前要插入的元素
        int left = 0; // 搜索范围的左边界
        int right = i; // 搜索范围的右边界

        // 使用二分查找找到 key 应该插入的位置
        while (left < right) {
            int mid = left + (right - left) / 2; // 找到中间位置
            if (arr[mid] > key) right = mid; // key 更小，查找左半部分
            else left = mid + 1; // key 更大或相等，查找右半部分
        }

        // 将元素移到正确位置
        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1]; // 向右移动元素，为 key 腾出空间
        }
        arr[left] = key; // 将 key 插入到正确位置

        //printArray(arr); // 打印每一步的结果
    }
}


// 希尔排序
void shellSort(vector<int>& arr) {
    // 初始化间隔大小，逐渐减小
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        // 对每个子数组进行插入排序
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i]; // 当前要插入的元素
            int j;

            // 插入排序的变种，根据 gap 进行元素移动
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // 向右移动元素
            }
            arr[j] = temp; // 插入元素

            //printArray(arr); // 打印每一步的结果
        }
    }
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // 遍历整个数组
    for (int i = 0; i < n - 1; i++) {
        // 将最大的元素“冒泡”到数组的末尾
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // 交换相邻元素
            }
        }
        //printArray(arr); // 打印每一步的结果
    }
}


// 快速排序的辅助函数 - 分区操作
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1;

    // 将小于基准的元素放到基准的左边
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // 交换元素
        }
    }
    swap(arr[i + 1], arr[high]); // 将基准元素放到正确的位置
    return i + 1; // 返回基准元素的位置
}

// 快速排序
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 执行分区操作
        quickSort(arr, low, pi - 1); // 递归排序左半部分
        quickSort(arr, pi + 1, high); // 递归排序右半部分
        //printArray(arr); // 打印每一步的结果
    }
}


// 堆调整（heapify）函数
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 当前节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 找出当前节点及其子节点中的最大值
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是当前节点，调整堆
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // 递归调整子堆
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // 一个个从堆顶取出元素
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // 将当前最大元素放到数组末尾
        heapify(arr, i, 0); // 重新调整堆
        //printArray(arr); // 打印每一步的结果
    }
}

// 用于测试排序算法的函数
void testSort(function<void(vector<int>&)> sortFunc, vector<int> arr, const string& sortName, const string& arrayName) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << sortName << " on " << arrayName << " took " << duration.count() << " microseconds" << endl;
}

vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }

    return merged;
}

int main() {
    // 完全随机序列
    vector<int> randomArray1 = {12, 11, 13, 5, 6, 7};
    vector<int> randomArray2 = {33, 17, 20, 29, 26, 31, 15};

    // 部分有序序列
    vector<int> partiallySortedArray1 = {1, 3, 5, 4, 2, 6};
    vector<int> partiallySortedArray2 = {10, 12, 15, 14, 13, 16, 11};

    // 几乎完全有序序列
    vector<int> nearlySortedArray1 = {2, 1, 3, 4, 5, 6};
    vector<int> nearlySortedArray2 = {21, 22, 23, 25, 24, 26, 27};

    // 倒序序列
    vector<int> reversedArray1 = {7, 6, 5, 4, 3, 2, 1};
    vector<int> reversedArray2 = {30, 29, 28, 27, 26, 25, 24};

    // 含有重复元素的序列
    vector<int> arrayWithDuplicates1 = {5, 6, 5, 7, 6, 8, 6};
    vector<int> arrayWithDuplicates2 = {20, 19, 20, 18, 19, 17, 20};


    // 随机数组，较大的数据集
    vector<int> largeRandomArray1 = {55, 23, 64, 12, 37, 81, 29, 44, 78, 57, 16, 33, 49, 67, 92, 71, 28, 85, 60, 34};
    vector<int> largeRandomArray2 = {100, 95, 88, 76, 45, 67, 59, 42, 30, 13, 22, 11, 5, 79, 83, 97, 63, 74, 54, 21};

    // 近似有序的大数组
    vector<int> largeNearlySortedArray = {1, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 20};

    // 包含重复元素的大数组
    vector<int> largeArrayWithDuplicates = {12, 5, 12, 8, 7, 5, 6, 12, 5, 9, 7, 6, 12, 5, 7, 8, 9, 7, 6, 5};

    // 定义测试用例名称
    vector<string> testArrayNames = {
            "Random Array 1", "Random Array 2", "Partially Sorted Array 1", "Partially Sorted Array 2",
            "Nearly Sorted Array 1", "Nearly Sorted Array 2", "Reversed Array 1", "Reversed Array 2",
            "Array With Duplicates 1", "Array With Duplicates 2", "Large Random Array 1", "Large Random Array 2",
            "Large Nearly Sorted Array", "Large Array With Duplicates"
    };

    vector<vector<int>> testArrays = {
            randomArray1, randomArray2, partiallySortedArray1, partiallySortedArray2,
            nearlySortedArray1, nearlySortedArray2, reversedArray1, reversedArray2,
            arrayWithDuplicates1, arrayWithDuplicates2, largeRandomArray1, largeRandomArray2,
            largeNearlySortedArray, largeArrayWithDuplicates
    };

    // 定义排序方法和它们的名称
    vector<pair<function<void(vector<int>&)>, string>> sortingMethods = {
            {binaryInsertionSort, "Binary Insertion Sort"},
            {shellSort, "Shell Sort"},
            {bubbleSort, "Bubble Sort"},
            {[](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort"},
            {heapSort, "Heap Sort"}
    };

    // 循环遍历排序方法和测试数组
    for (auto& method : sortingMethods) {
        for (size_t i = 0; i < testArrays.size(); ++i) {
            testSort(method.first, testArrays[i], method.second, testArrayNames[i]);
        }
        cout << "---------------------------" << endl;
    }

    // 测试样例1: 两个有序数组的合并
    vector<int> arr1 = {1, 3, 5, 7, 9, 11, 2021};
    vector<int> arr2 = {2, 4, 6, 8, 10, 12, 164};

    // 测试样例2: 其中一个数组为空
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 8 ,9};
    vector<int> arr4; // 空数组

    // 测试样例3: 重复元素
    vector<int> arr5 = {5, 5, 5, 5, 5, 5, 5, 5};
    vector<int> arr6 = {5, 5, 5, 5, 5, 5, 5, 5};

    // 测试样例4: 数组1比数组2长
    vector<int> arr7 = {1, 4, 7, 9, 10, 13, 18, 49, 85};
    vector<int> arr8 = {2, 5, 8, 11, 14, 17};

    // 测试样例5: 数组2比数组1长
    vector<int> arr9 = {2, 4, 6, 8, 10, 12};
    vector<int> arr10 = {1, 3, 5, 7, 8, 9, 10, 234, 567};

    // 测试样例6: 两个空数组
    vector<int> arr11;
    vector<int> arr12;

    vector<vector<int>> testCases = {arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12};

    for (int i = 0; i < testCases.size(); i += 2) {
        auto start = high_resolution_clock::now();

        vector<int> merged = mergeTwoSortedArrays(testCases[i], testCases[i + 1]);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Merged Array " << i / 2 + 1 << ": ";
        for (int element : merged) {
            cout << element << " ";
        }
        cout << endl;

        cout << "Time taken for merging " << i / 2 + 1 << ": " << duration.count() << " microseconds" << endl;
    }

    return 0;
}

