#include <iostream>
#include <algorithm>
using namespace std;

// AVL树的节点定义
template<class K, class V>
struct AVLTreeNode {
    K key;
    V value;
    int balance_factor;
    AVLTreeNode<K, V>* parent;
    AVLTreeNode<K, V>* left;
    AVLTreeNode<K, V>* right;

    AVLTreeNode(const K& key = K(), const V& value = V())
        : key(key), value(value), balance_factor(0), parent(nullptr), left(nullptr), right(nullptr) {}
};

template<class K, class V>
class AVLTree {
public:
    AVLTree() : root_(nullptr) {}

    // 插入操作，将键值对插入到AVL树中
    bool Insert(const K& key, const V& value);

    // 中序遍历AVL树，按键的升序顺序输出键值对
    void InOrder();

    // 检查AVL树是否平衡
    bool IsBalanced();

    // 计算AVL树的高度
    int Height();

protected:
    // 右旋操作
    void RotateRight(AVLTreeNode<K, V>*& parent);

    // 左旋操作
    void RotateLeft(AVLTreeNode<K, V>*& parent);

    // 右左双旋操作
    void RotateRightLeft(AVLTreeNode<K, V>*& parent);

    // 左右双旋操作
    void RotateLeftRight(AVLTreeNode<K, V>*& parent);

    // 中序遍历辅助函数
    void InOrderTraversal(AVLTreeNode<K, V>* root);

    // 判断树是否平衡的辅助函数
    bool IsBalancedHelper(AVLTreeNode<K, V>* root);

    // 计算树高度的辅助函数
    int HeightHelper(AVLTreeNode<K, V>* root);

    // 插入后更新平衡因子并进行旋转调整的辅助函数
    void UpdateBalanceFactorsAfterInsert(AVLTreeNode<K, V>* parent, AVLTreeNode<K, V>* current);

private:
    AVLTreeNode<K, V>* root_;
};

// 插入操作，将键值对插入到AVL树中
template<class K, class V>
bool AVLTree<K, V>::Insert(const K& key, const V& value) {
    if (root_ == nullptr) {
        root_ = new AVLTreeNode<K, V>(key, value);
        return true;
    }

    AVLTreeNode<K, V>* current = root_;
    AVLTreeNode<K, V>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return false; // Key already exists.
        }
    }

    current = new AVLTreeNode<K, V>(key, value);
    current->parent = parent;
    if (key < parent->key) {
        parent->left = current;
    } else {
        parent->right = current;
    }

    UpdateBalanceFactorsAfterInsert(parent, current);
    return true;
}

// 右旋操作
template<class K, class V>
void AVLTree<K, V>::RotateRight(AVLTreeNode<K, V>*& parent) {
    AVLTreeNode<K, V>* new_parent = parent->left;
    parent->left = new_parent->right;
    if (new_parent->right != nullptr) {
        new_parent->right->parent = parent;
    }
    new_parent->right = parent;
    new_parent->parent = parent->parent;
    parent->parent = new_parent;
    parent = new_parent;
}

// 左旋操作
template<class K, class V>
void AVLTree<K, V>::RotateLeft(AVLTreeNode<K, V>*& parent) {
    AVLTreeNode<K, V>* new_parent = parent->right;
    parent->right = new_parent->left;
    if (new_parent->left != nullptr) {
        new_parent->left->parent = parent;
    }
    new_parent->left = parent;
    new_parent->parent = parent->parent;
    parent->parent = new_parent;
    parent = new_parent;
}

// 右左双旋操作
template<class K, class V>
void AVLTree<K, V>::RotateRightLeft(AVLTreeNode<K, V>*& parent) {
    RotateRight(parent->right);
    RotateLeft(parent);
}

// 左右双旋操作
template<class K, class V>
void AVLTree<K, V>::RotateLeftRight(AVLTreeNode<K, V>*& parent) {
    RotateLeft(parent->left);
    RotateRight(parent);
}

// 中序遍历辅助函数
template<class K, class V>
void AVLTree<K, V>::InOrderTraversal(AVLTreeNode<K, V>* root) {
    if (root == nullptr) {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->key << " ";
    InOrderTraversal(root->right);
}

// 判断树是否平衡的辅助函数
template<class K, class V>
bool AVLTree<K, V>::IsBalancedHelper(AVLTreeNode<K, V>* root) {
    if (root == nullptr) {
        return true;
    }
    int balance_factor = HeightHelper(root->right) - HeightHelper(root->left);
    return abs(balance_factor) < 2 && IsBalancedHelper(root->left) && IsBalancedHelper(root->right);
}

// 计算树高度的辅助函数
template<class K, class V>
int AVLTree<K, V>::HeightHelper(AVLTreeNode<K, V>* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_height = HeightHelper(root->left);
    int right_height = HeightHelper(root->right);
    return 1 + max(left_height, right_height);
}

// 插入后更新平衡因子并进行旋转调整的辅助函数
template<class K, class V>
void AVLTree<K, V>::UpdateBalanceFactorsAfterInsert(AVLTreeNode<K, V>* parent, AVLTreeNode<K, V>* current) {
    while (parent != nullptr) {
        if (current == parent->left) {
            parent->balance_factor--;
        } else {
            parent->balance_factor++;
        }

        if (parent->balance_factor == 0) {
            break;
        } else if (parent->balance_factor == -1 || parent->balance_factor == 1) {
            current = parent;
            parent = parent->parent;
        } else {
            if (parent->balance_factor == 2) {
                if (current->balance_factor == 1) {
                    RotateLeft(parent);
                } else {
                    RotateRightLeft(parent);
                }
            } else if (parent->balance_factor == -2) {
                if (current->balance_factor == -1) {
                    RotateRight(parent);
                } else {
                    RotateLeftRight(parent);
                }
            }
            break;
        }
    }
}

// 中序遍历的公共接口
template<class K, class V>
void AVLTree<K, V>::InOrder() {
    InOrderTraversal(root_);
}

// 判断AVL树是否平衡的公共接口
template<class K, class V>
bool AVLTree<K, V>::IsBalanced() {
    return IsBalancedHelper(root_);
}

// 计算树的高度的公共接口
template<class K, class V>
int AVLTree<K, V>::Height() {
    return HeightHelper(root_);
}

bool RunTest() {
    AVLTree<int, int> tree;

    // 测试用例1: 添加一系列随机数值
    int test1[] = {16, 3, 7, 11, 9, 26, 18, 14, 15, 1, 5, 12, 20};
    for (size_t i = 0; i < sizeof(test1) / sizeof(test1[0]); ++i) {
        tree.Insert(test1[i], i);
    }
    std::cout << "Test 1 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 测试用例2: 添加顺序数值
    tree = AVLTree<int, int>(); // 重置树
    for (int i = 1; i <= 10; ++i) {
        tree.Insert(i, i);
    }
    std::cout << "Test 2 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 测试用例3: 添加逆序数值
    tree = AVLTree<int, int>(); // 重置树
    for (int i = 10; i > 0; --i) {
        tree.Insert(i, i);
    }
    std::cout << "Test 3 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 测试用例4: 添加相同数值
    tree = AVLTree<int, int>(); // 重置树
    for (int i = 0; i < 5; ++i) {
        tree.Insert(5, i);
    }
    std::cout << "Test 4 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 测试用例5: 添加单个数值
    tree = AVLTree<int, int>(); // 重置树
    tree.Insert(100, 100);
    std::cout << "Test 5 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 测试用例6: 添加更多数值
    int test2[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 9, 11, 14, 16, 19, 2, 8, 13, 17, 20};
    tree = AVLTree<int, int>(); // 重置树
    for (size_t i = 0; i < sizeof(test2) / sizeof(test2[0]); ++i) {
        tree.Insert(test2[i], i);
    }
    std::cout << "Test 6 - InOrder Traversal: ";
    tree.InOrder();
    std::cout << "Height=" << tree.Height() << std::endl;
    std::cout << "Is Balanced: " << (tree.IsBalanced() ? "Yes" : "No") << std::endl;

    // 检查是否所有测试用例通过
    return tree.IsBalanced();
}

int main() {
    bool pass = RunTest();
    if (pass) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
    return 0;
}
