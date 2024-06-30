#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int v, int w, int weight); // 添加一条边
    std::vector<int> BFS(int vertex); // 广度优先遍历
    std::vector<int> DFS_non_recursive(int vertex); // 非递归深度优先遍历
    std::vector<int> DFS_recursive(int vertex); // 递归深度优先遍历
    bool hasCycle(); // 判断图中是否存在环
    std::vector<int> round(int v, int w); // 求无向图的两个顶点之间的简单路径,若存在打印出来，不存在说明不存在
    std::vector<std::pair<int, std::pair<int, int>>> KruskalMST(); // Kruskal算法求最小生成树
    void printMST(); // 打印最小生成树
    std::vector<int> findHamiltonianCycle(); // 求一条包含所有顶点的回路
    void printGraph(); // 可视化打印图

private:
    int V; // 图的顶点数
    std::vector<std::vector<std::pair<int, int>>> adjList; // 存储图的邻接表
    bool isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack); // 辅助函数判断是否有环
    void DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& result); // 辅助函数深度优先遍历
    bool findHamiltonianCycleUtil(int v, std::vector<bool>& visited, std::vector<int>& path, int count); // 辅助函数求包含所有顶点的回路
};

#endif
