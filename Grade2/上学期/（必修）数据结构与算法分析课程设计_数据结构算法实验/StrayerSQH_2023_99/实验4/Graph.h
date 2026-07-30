#ifndef  GRAPH_H
#define  GRAPH_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "CourseInformation.h"
#include "GeneralList.h"
#include "QueueList.h"
#include "CourseStack.h"
#include "CourseInformationOverview.h"
#include "ClassInEachTerm.h"

using namespace std;

class Graph {
private:
    int courseNum;
    vector<CourseInformation*> adj;
public:
    vector<CourseInformation*> result; // 存储拓扑排序结果
    Graph(int cN) : courseNum(cN) {}

    void AddCourse(CourseInformation* course)
    {
        adj.push_back(course);
    }

    void AddPrerequisite(CourseInformation* before, CourseInformation* after)
    {
        after->prerequisites.push_back(before);
        before->successors.push_back(after);
    }

    void TopologicalSort()
    {
        vector<int> in_degree(courseNum, 0); // 存储每个课程的入度

        // 初始化入度
        for (int i = 0; i < courseNum; ++i)
        {
            CourseInformation* course = adj[i];
            for (CourseInformation* pre : course->prerequisites)
            {
                in_degree[i]++;
            }
        }

        // 将所有入度为0的课程放入队列
        queue<int> q;
        for (int i = 0; i < courseNum; ++i)
        {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // 执行拓扑排序
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(adj[u]);

            for (CourseInformation* v : adj[u]->successors)
            {
                int index;
                auto it = find(adj.begin(), adj.end(), v);
                if (it != adj.end())
                {
                    index = it - adj.begin();
                }
                in_degree[index]--;
                if (in_degree[index] == 0) {
                    q.push(index);
                }
            }
        }
        if (result.size() != courseNum)
        {
            cout << "存在循环依赖课程，无法安排课表！" << endl;
            exit(0);
        }
    }
};

#endif // ! GRAPH_H

