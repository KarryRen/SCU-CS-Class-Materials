#include "binary_tree.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinaryTree::setRoot(TreeNode* node) {
    root = node;
}

TreeNode* BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::inorderTraversalRec(TreeNode* node) const {
    if (node) {
        inorderTraversalRec(node->left);
        std::cout << node->val << " ";
        inorderTraversalRec(node->right);
    }
}

void BinaryTree::preorderTraversalRec(TreeNode* node) const {
    if (node) {
        std::cout << node->val << " ";
        preorderTraversalRec(node->left);
        preorderTraversalRec(node->right);
    }
}

void BinaryTree::postorderTraversalRec(TreeNode* node) const {
    if (node) {
        postorderTraversalRec(node->left);
        postorderTraversalRec(node->right);
        std::cout << node->val << " ";
    }
}

std::vector<int> BinaryTree::inorderTraversal(TreeNode* root) const {
    std::vector<int> result;
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

std::vector<int> BinaryTree::preorderTraversal(TreeNode* root) const {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);

        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return result;
}

std::vector<int> BinaryTree::postorderTraversal(TreeNode* root) const {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);

        if (node->left) s.push(node->left);
        if (node->right) s.push(node->right);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> BinaryTree::getLeaves(TreeNode* root) const {
    std::vector<int> leaves;
    if (!root) return leaves;

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();

        if (!node->left && !node->right)
            leaves.push_back(node->val);

        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return leaves;
}

int BinaryTree::countLeaves(TreeNode* root) const {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int BinaryTree::getHeight(TreeNode* root) const {
    if (!root) return 0;
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

void BinaryTree::printTree(TreeNode* root) const {
    printSubtree(root, "", false);
}

void BinaryTree::printSubtree(TreeNode* node, std::string indent, bool isLeft) const {
    if (node) {
        std::cout << indent;

        if (isLeft) {
            std::cout << "\u251C\u2500\u2500 ";
            indent += "\u2502   ";
        } else {
            std::cout << "\u2514\u2500\u2500 ";
            indent += "    ";
        }

        std::cout << node->val << std::endl;

        printSubtree(node->left, indent, true);
        printSubtree(node->right, indent, false);
    } else {
        std::cout << indent << "\u2514\u2500\u2500 null" << std::endl;
    }
}


void BinaryTree::buildHuffmanTree(const std::vector<std::pair<char, int>>& frequencies) {
    // Lambda to compare two TreeNode pointers based on their frequencies
    auto compare = [](TreeNode* left, TreeNode* right) {
        return left->val > right->val;
    };

    // Priority queue to store the nodes based on frequency
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, decltype(compare)> pq(compare);

    // Step 1: Create a leaf node for each character and enqueue it to the priority queue.
    for (const auto& entry : frequencies) {
        TreeNode* node = new TreeNode(entry.second);  // Use frequency as value for the node
        pq.push(node);
    }

    // Step 2: Build the Huffman Tree
    while (pq.size() > 1) {
        TreeNode* left = pq.top(); pq.pop();
        TreeNode* right = pq.top(); pq.pop();

        // Create a new node with combined frequency
        TreeNode* combined = new TreeNode(left->val + right->val);
        combined->left = left;
        combined->right = right;

        // Enqueue the new node
        pq.push(combined);
    }

    // Set the root of the Huffman Tree
    root = pq.top();  // the last node in the queue is the root of the Huffman tree
}
