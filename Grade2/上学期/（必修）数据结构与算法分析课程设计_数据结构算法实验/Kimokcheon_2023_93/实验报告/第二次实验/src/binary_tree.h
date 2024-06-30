#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode *root;  // Root data member
    void destroyTree(TreeNode *node);  // Private function to recursively delete the tree

public:
    BinaryTree();

    ~BinaryTree();

    TreeNode *getRoot() const;
    void setRoot(TreeNode* node);

    // Recursive traversals
    void inorderTraversalRec(TreeNode *root) const;

    void preorderTraversalRec(TreeNode *root) const;

    void postorderTraversalRec(TreeNode *root) const;

    // Non-recursive traversals
    std::vector<int> inorderTraversal(TreeNode *root) const;

    std::vector<int> preorderTraversal(TreeNode *root) const;

    std::vector<int> postorderTraversal(TreeNode *root) const;

    // Application functions
    std::vector<int> getLeaves(TreeNode *root) const;

    int countLeaves(TreeNode *root) const;

    int getHeight(TreeNode *root) const;

    void printTree(TreeNode *root) const;
    void printSubtree(TreeNode* node, std::string indent, bool isLeft) const;


    // Function to build a Huffman tree
    void buildHuffmanTree(const std::vector<std::pair<char, int>> &frequencies);

};
#endif //BINARY_TREE_H
