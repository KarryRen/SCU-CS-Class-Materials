#include "binary_tree.h"
#include "graph.h"
#include <iostream>

void runBinaryTreeTests();
void runGraphTests();


int main() {
    runBinaryTreeTests();
    runGraphTests();
    return 0;

}

void runBinaryTreeTests() {
    // Sample 1: Character frequencies example (character, frequency)
    std::vector<std::pair<char, int>> frequencies1 = {
            {'A', 5},
            {'B', 9},
            {'C', 12},
            {'D', 13},
            {'E', 16},
            {'F', 45}
    };
    BinaryTree Test1tree;
    Test1tree.buildHuffmanTree(frequencies1);
    std::cout << "Sample 1: Huffman Tree" << std::endl;

    // Recursive traversals
    std::cout << "Recursive Inorder Traversal: ";
    Test1tree.inorderTraversalRec(Test1tree.getRoot());
    std::cout << std::endl;

    std::cout << "Recursive Preorder Traversal: ";
    Test1tree.preorderTraversalRec(Test1tree.getRoot());
    std::cout << std::endl;

    std::cout << "Recursive Postorder Traversal: ";
    Test1tree.postorderTraversalRec(Test1tree.getRoot());
    std::cout << std::endl;

    // Non-recursive traversals
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test1tree.inorderTraversal(Test1tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test1tree.preorderTraversal(Test1tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test1tree.postorderTraversal(Test1tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Application functions
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test1tree.getLeaves(Test1tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Total Leaf Nodes: " << Test1tree.countLeaves(Test1tree.getRoot()) << std::endl;
    std::cout << "Height of the Tree: " << Test1tree.getHeight(Test1tree.getRoot()) << std::endl;

    // Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test1tree.printTree(Test1tree.getRoot());
    std::cout << std::endl;

    // Sample 2: Binary Search Tree example
    BinaryTree Test2tree;
    TreeNode* node1 = new TreeNode(8);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(10);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(6);
    TreeNode* node6 = new TreeNode(14);
    TreeNode* node7 = new TreeNode(4);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(13);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node5->left = node7;
    node5->right = node8;
    node6->left = node9;
    Test2tree.setRoot(node1);
    std::cout << "Sample 2: Binary Search Tree" << std::endl;

    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test2tree.inorderTraversalRec(Test2tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test2tree.preorderTraversalRec(Test2tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test2tree.postorderTraversalRec(Test2tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test2tree.inorderTraversal(Test2tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test2tree.preorderTraversal(Test2tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test2tree.postorderTraversal(Test2tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test2tree.getLeaves(Test2tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test2tree.countLeaves(Test2tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test2tree.getHeight(Test2tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test2tree.printTree(Test2tree.getRoot());
    std::cout << std::endl;


    // Sample 3: Balanced Binary Tree example
    BinaryTree Test3tree;
    TreeNode* node10 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node14 = new TreeNode(5);
    TreeNode* node15 = new TreeNode(6);
    TreeNode* node16 = new TreeNode(7);
    node13->left = node11;
    node13->right = node15;
    node11->left = node10;
    node11->right = node12;
    node15->left = node14;
    node15->right = node16;
    Test3tree.setRoot(node13);
    std::cout << "Sample 3: Balanced Binary Tree" << std::endl;

    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test3tree.inorderTraversalRec(Test3tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test3tree.preorderTraversalRec(Test3tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test3tree.postorderTraversalRec(Test3tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test3tree.inorderTraversal(Test3tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test3tree.preorderTraversal(Test3tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test3tree.postorderTraversal(Test3tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test3tree.getLeaves(Test3tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test3tree.countLeaves(Test3tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test3tree.getHeight(Test3tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test3tree.printTree(Test3tree.getRoot());
    std::cout << std::endl;


    // Sample 4: Skewed Binary Tree example
    BinaryTree Test4tree;
    TreeNode* node17 = new TreeNode(1);
    TreeNode* node18 = new TreeNode(2);
    TreeNode* node19 = new TreeNode(3);
    TreeNode* node20 = new TreeNode(4);
    TreeNode* node21 = new TreeNode(5);
    TreeNode* node22 = new TreeNode(6);
    TreeNode* node23 = new TreeNode(7);
    node17->right = node18;
    node18->right = node19;
    node19->right = node20;
    node20->right = node21;
    node21->right = node22;
    node22->right = node23;
    Test4tree.setRoot(node17);
    std::cout << "Sample 4: Skewed Binary Tree" << std::endl;
    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test4tree.inorderTraversalRec(Test4tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test4tree.preorderTraversalRec(Test4tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test4tree.postorderTraversalRec(Test4tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test4tree.inorderTraversal(Test4tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test4tree.preorderTraversal(Test4tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test4tree.postorderTraversal(Test4tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test4tree.getLeaves(Test4tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test4tree.countLeaves(Test4tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test4tree.getHeight(Test4tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test4tree.printTree(Test4tree.getRoot());
    std::cout << std::endl;


    // Sample 5: Full Binary Tree example
    BinaryTree Test5tree;
    TreeNode* node24 = new TreeNode(1);
    TreeNode* node25 = new TreeNode(2);
    TreeNode* node26 = new TreeNode(3);
    TreeNode* node27 = new TreeNode(4);
    TreeNode* node28 = new TreeNode(5);
    TreeNode* node29 = new TreeNode(6);
    TreeNode* node30 = new TreeNode(7);
    node24->left = node25;
    node24->right = node26;
    node25->left = node27;
    node25->right = node28;
    node26->left = node29;
    node26->right = node30;
    Test5tree.setRoot(node24);
    std::cout << "Sample 5: Full Binary Tree" << std::endl;
    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test5tree.inorderTraversalRec(Test5tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test5tree.preorderTraversalRec(Test5tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test5tree.postorderTraversalRec(Test5tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test5tree.inorderTraversal(Test5tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test5tree.preorderTraversal(Test5tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test5tree.postorderTraversal(Test5tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test5tree.getLeaves(Test5tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test5tree.countLeaves(Test5tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test5tree.getHeight(Test5tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test5tree.printTree(Test5tree.getRoot());
    std::cout << std::endl;


    // Sample 6: Complete Binary Tree example
    BinaryTree Test6tree;
    TreeNode* node31 = new TreeNode(1);
    TreeNode* node32 = new TreeNode(2);
    TreeNode* node33 = new TreeNode(3);
    TreeNode* node34 = new TreeNode(4);
    TreeNode* node35 = new TreeNode(5);
    TreeNode* node36 = new TreeNode(6);
    TreeNode* node37 = new TreeNode(7);
    node31->left = node32;
    node31->right = node33;
    node32->left = node34;
    node32->right = node35;
    node33->left = node36;
    node33->right = node37;
    Test6tree.setRoot(node31);
    std::cout << "Sample 6: Complete Binary Tree" << std::endl;
    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test6tree.inorderTraversalRec(Test6tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test6tree.preorderTraversalRec(Test6tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test6tree.postorderTraversalRec(Test6tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test6tree.inorderTraversal(Test6tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test6tree.preorderTraversal(Test6tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test6tree.postorderTraversal(Test6tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test6tree.getLeaves(Test6tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test6tree.countLeaves(Test6tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test6tree.getHeight(Test6tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test6tree.printTree(Test6tree.getRoot());
    std::cout << std::endl;


    // Sample 7: Random Binary Tree example
    BinaryTree Test7tree;
    TreeNode* node38 = new TreeNode(5);
    TreeNode* node39 = new TreeNode(2);
    TreeNode* node40 = new TreeNode(6);
    TreeNode* node41 = new TreeNode(1);
    TreeNode* node42 = new TreeNode(3);
    TreeNode* node43 = new TreeNode(8);
    TreeNode* node44 = new TreeNode(4);
    TreeNode* node45 = new TreeNode(7);
    node38->left = node39;
    node38->right = node40;
    node39->left = node41;
    node39->right = node42;
    node40->right = node43;
    node42->left = node44;
    node42->right = node45;
    Test7tree.setRoot(node38);
    std::cout << "Sample 7: Random Binary Tree" << std::endl;
    // Recursive Inorder Traversal
    std::cout << "Recursive Inorder Traversal: ";
    Test7tree.inorderTraversalRec(Test7tree.getRoot());
    std::cout << std::endl;

// Recursive Preorder Traversal
    std::cout << "Recursive Preorder Traversal: ";
    Test7tree.preorderTraversalRec(Test7tree.getRoot());
    std::cout << std::endl;

// Recursive Postorder Traversal
    std::cout << "Recursive Postorder Traversal: ";
    Test7tree.postorderTraversalRec(Test7tree.getRoot());
    std::cout << std::endl;

// Non-recursive Inorder Traversal
    std::cout << "Non-recursive Inorder Traversal: ";
    for (int val : Test7tree.inorderTraversal(Test7tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Preorder Traversal
    std::cout << "Non-recursive Preorder Traversal: ";
    for (int val : Test7tree.preorderTraversal(Test7tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Non-recursive Postorder Traversal
    std::cout << "Non-recursive Postorder Traversal: ";
    for (int val : Test7tree.postorderTraversal(Test7tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// List of Leaf Nodes
    std::cout << "List of Leaf Nodes: ";
    for (int val : Test7tree.getLeaves(Test7tree.getRoot())) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// Total Leaf Nodes
    std::cout << "Total Leaf Nodes: " << Test7tree.countLeaves(Test7tree.getRoot()) << std::endl;

// Height of the Tree
    std::cout << "Height of the Tree: " << Test7tree.getHeight(Test7tree.getRoot()) << std::endl;

// Print the Tree
    std::cout << "Printing the Tree:" << std::endl;
    Test7tree.printTree(Test7tree.getRoot());
    std::cout << std::endl;

}


void runGraphTests() {
    // Test case 0
    Graph g(6);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 8);
    g.addEdge(4, 5, 9);

    std::cout << "Adjacency list of the graph:" << std::endl;
    g.printGraph();
    std::cout << std::endl;

    std::cout << "Breadth-first traversal result:" << std::endl;
    std::vector<int> bfsResult = g.BFS(0);
    for (int i = 0; i < bfsResult.size(); i++) {
        std::cout << bfsResult[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Non-recursive depth-first traversal result:" << std::endl;
    std::vector<int> dfsNonRecursiveResult = g.DFS_non_recursive(0);
    for (int i = 0; i < dfsNonRecursiveResult.size(); i++) {
        std::cout << dfsNonRecursiveResult[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Recursive depth-first traversal result:" << std::endl;
    std::vector<int> dfsRecursiveResult = g.DFS_recursive(0);
    for (int i = 0; i < dfsRecursiveResult.size(); i++) {
        std::cout << dfsRecursiveResult[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Does the graph contain a cycle:" << std::endl;
    if (g.hasCycle()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Path from vertex 0 to 5:" << std::endl;
    std::vector<int> path = g.round(0, 5);
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Minimum spanning tree:" << std::endl;
    g.printMST();
    std::cout << std::endl;

    std::cout << "Hamiltonian cycle that includes all vertices:" << std::endl;
    std::vector<int> hamiltonianPath = g.findHamiltonianCycle();
    if (!hamiltonianPath.empty()) {
        for (int i = 0; i < hamiltonianPath.size(); i++) {
            std::cout << hamiltonianPath[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Does not exist" << std::endl;
    }


    // Test case 1
    Graph g1(5);

    g1.addEdge(0, 1, 2);
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 3, 4);
    g1.addEdge(2, 4, 5);
    g1.addEdge(3, 4, 7);

    std::cout << "Adjacency list of graph 1:" << std::endl;
    g1.printGraph();
    std::cout << std::endl;

    std::cout << "Breadth-first traversal result for graph 1:" << std::endl;
    std::vector<int> bfsResult1 = g1.BFS(0);
    for (int i = 0; i < bfsResult1.size(); i++) {
        std::cout << bfsResult1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Non-recursive depth-first traversal result for graph 1:" << std::endl;
    std::vector<int> dfsNonRecursiveResult1 = g1.DFS_non_recursive(0);
    for (int i = 0; i < dfsNonRecursiveResult1.size(); i++) {
        std::cout << dfsNonRecursiveResult1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Recursive depth-first traversal result for graph 1:" << std::endl;
    std::vector<int> dfsRecursiveResult1 = g1.DFS_recursive(0);
    for (int i = 0; i < dfsRecursiveResult1.size(); i++) {
        std::cout << dfsRecursiveResult1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Does graph 1 contain a cycle:" << std::endl;
    if (g1.hasCycle()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Path from vertex 0 to 4 in graph 1:" << std::endl;
    std::vector<int> path1 = g1.round(0, 4);
    for (int i = 0; i < path1.size(); i++) {
        std::cout << path1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Minimum spanning tree of graph 1:" << std::endl;
    g1.printMST();
    std::cout << std::endl;

    std::cout << "Hamiltonian cycle that includes all vertices in graph 1:" << std::endl;
    std::vector<int> hamiltonianPath1 = g1.findHamiltonianCycle();
    if (!hamiltonianPath1.empty()) {
        for (int i = 0; i < hamiltonianPath1.size(); i++) {
            std::cout << hamiltonianPath1[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Does not exist" << std::endl;
    }



    std::cout << "Adjacency list of graph 1:" << std::endl;
    g1.printGraph();
    std::cout << std::endl;

    // Perform other operations on g1

    // Test case 2
    Graph g2(4);

    g2.addEdge(0, 1, 1);
    g2.addEdge(0, 2, 2);
    g2.addEdge(1, 3, 3);
    g2.addEdge(2, 3, 4);

    std::cout << "Adjacency list of graph 2:" << std::endl;
    g2.printGraph();
    std::cout << std::endl;

    std::cout << "Breadth-first traversal result for graph 2:" << std::endl;
    std::vector<int> bfsResult2 = g2.BFS(0);
    for (int i = 0; i < bfsResult2.size(); i++) {
        std::cout << bfsResult2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Non-recursive depth-first traversal result for graph 2:" << std::endl;
    std::vector<int> dfsNonRecursiveResult2 = g2.DFS_non_recursive(0);
    for (int i = 0; i < dfsNonRecursiveResult2.size(); i++) {
        std::cout << dfsNonRecursiveResult2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Recursive depth-first traversal result for graph 2:" << std::endl;
    std::vector<int> dfsRecursiveResult2 = g2.DFS_recursive(0);
    for (int i = 0; i < dfsRecursiveResult2.size(); i++) {
        std::cout << dfsRecursiveResult2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Does graph 2 contain a cycle:" << std::endl;
    if (g2.hasCycle()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Path from vertex 0 to 3 in graph 2:" << std::endl;
    std::vector<int> path2 = g2.round(0, 3);
    for (int i = 0; i < path2.size(); i++) {
        std::cout << path2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Minimum spanning tree of graph 2:" << std::endl;
    g2.printMST();
    std::cout << std::endl;

    std::cout << "Hamiltonian cycle that includes all vertices in graph 2:" << std::endl;
    std::vector<int> hamiltonianPath2 = g2.findHamiltonianCycle();
    if (!hamiltonianPath2.empty()) {
        for (int i = 0; i < hamiltonianPath2.size(); i++) {
            std::cout << hamiltonianPath2[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Does not exist" << std::endl;
    }

    Graph g3(10);

    g3.addEdge(0, 1, 2);
    g3.addEdge(0, 2, 3);
    g3.addEdge(1, 3, 4);
    g3.addEdge(2, 4, 5);
    g3.addEdge(3, 4, 7);
    g3.addEdge(3, 5, 8);
    g3.addEdge(4, 6, 9);
    g3.addEdge(5, 7, 10);
    g3.addEdge(6, 8, 11);
    g3.addEdge(7, 9, 12);
    g3.addEdge(8, 9, 13);

    std::cout << "Adjacency list of graph 3:" << std::endl;
    g3.printGraph();
    std::cout << std::endl;

    std::cout << "Breadth-first traversal result for graph 3:" << std::endl;
    std::vector<int> bfsResult3 = g3.BFS(0);
    for (int i = 0; i < bfsResult3.size(); i++) {
        std::cout << bfsResult3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Non-recursive depth-first traversal result for graph 3:" << std::endl;
    std::vector<int> dfsNonRecursiveResult3 = g3.DFS_non_recursive(0);
    for (int i = 0; i < dfsNonRecursiveResult3.size(); i++) {
        std::cout << dfsNonRecursiveResult3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Recursive depth-first traversal result for graph 3:" << std::endl;
    std::vector<int> dfsRecursiveResult3 = g3.DFS_recursive(0);
    for (int i = 0; i < dfsRecursiveResult3.size(); i++) {
        std::cout << dfsRecursiveResult3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Does graph 3 contain a cycle:" << std::endl;
    if (g3.hasCycle()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Path from vertex 0 to 9 in graph 3:" << std::endl;
    std::vector<int> path3 = g3.round(0, 9);
    for (int i = 0; i < path3.size(); i++) {
        std::cout << path3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Minimum spanning tree of graph 3:" << std::endl;
    g3.printMST();
    std::cout << std::endl;

    std::cout << "Hamiltonian cycle that includes all vertices in graph 3:" << std::endl;
    std::vector<int> hamiltonianPath3 = g3.findHamiltonianCycle();
    if (!hamiltonianPath3.empty()) {
        for (int i = 0; i < hamiltonianPath3.size(); i++) {
            std::cout << hamiltonianPath3[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Does not exist" << std::endl;
    }

    Graph g4(14);

    g4.addEdge(0, 1, 2);
    g4.addEdge(0, 2, 3);
    g4.addEdge(1, 3, 4);
    g4.addEdge(2, 4, 5);
    g4.addEdge(3, 4, 7);
    g4.addEdge(3, 5, 8);
    g4.addEdge(4, 6, 9);
    g4.addEdge(5, 7, 10);
    g4.addEdge(6, 8, 11);
    g4.addEdge(7, 9, 12);
    g4.addEdge(8, 9, 13);
    g4.addEdge(8, 10, 14);
    g4.addEdge(9, 11, 15);
    g4.addEdge(10, 12, 16);
    g4.addEdge(11, 13, 17);
    g4.addEdge(12, 13, 18);

    std::cout << "Adjacency list of graph 4:" << std::endl;
    g4.printGraph();
    std::cout << std::endl;

    std::cout << "Breadth-first traversal result for graph 4:" << std::endl;
    std::vector<int> bfsResult4 = g4.BFS(0);
    for (int i = 0; i < bfsResult4.size(); i++) {
        std::cout << bfsResult4[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Non-recursive depth-first traversal result for graph 4:" << std::endl;
    std::vector<int> dfsNonRecursiveResult4 = g4.DFS_non_recursive(0);
    for (int i = 0; i < dfsNonRecursiveResult4.size(); i++) {
        std::cout << dfsNonRecursiveResult4[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Recursive depth-first traversal result for graph 4:" << std::endl;
    std::vector<int> dfsRecursiveResult4 = g4.DFS_recursive(0);
    for (int i = 0; i < dfsRecursiveResult4.size(); i++) {
        std::cout << dfsRecursiveResult4[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Does graph 4 contain a cycle:" << std::endl;
    if (g4.hasCycle()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Path from vertex 0 to 13 in graph 4:" << std::endl;
    std::vector<int> path4 = g4.round(0, 13);
    for (int i = 0; i < path4.size(); i++) {
        std::cout << path4[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Minimum spanning tree of graph 4:" << std::endl;
    g4.printMST();
    std::cout << std::endl;

    std::cout << "Hamiltonian cycle that includes all vertices in graph 4:" << std::endl;
    std::vector<int> hamiltonianPath4 = g4.findHamiltonianCycle();
    if (!hamiltonianPath4.empty()) {
        for (int i = 0; i < hamiltonianPath4.size(); i++) {
            std::cout << hamiltonianPath4[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Does not exist" << std::endl;
    }

}