#include "graph.h"

using namespace std;

Graph::Graph(int vertices) {
    V = vertices;
    adjList.resize(V);
}

Graph::~Graph() {}

void Graph::addEdge(int v, int w, int weight) {
    adjList[v].push_back(make_pair(w, weight));
    adjList[w].push_back(make_pair(v, weight));
}

vector<int> Graph::BFS(int vertex) {
    vector<int> result;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(v);

        for (int i = 0; i < adjList[v].size(); i++) {
            int w = adjList[v][i].first;
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }

    return result;
}

vector<int> Graph::DFS_non_recursive(int vertex) {
    vector<int> result;
    vector<bool> visited(V, false);
    stack<int> s;

    visited[vertex] = true;
    s.push(vertex);

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        result.push_back(v);

        for (int i = 0; i < adjList[v].size(); i++) {
            int w = adjList[v][i].first;
            if (!visited[w]) {
                visited[w] = true;
                s.push(w);
            }
        }
    }

    return result;
}

vector<int> Graph::DFS_recursive(int vertex) {
    vector<int> result;
    vector<bool> visited(V, false);
    DFSUtil(vertex, visited, result);
    return result;
}

bool Graph::hasCycle() {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (isCyclicUtil(i, visited, recStack)) {
            return true;
        }
    }

    return false;
}

bool Graph::isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < adjList[v].size(); i++) {
            int w = adjList[v][i].first;
            if (!visited[w] && isCyclicUtil(w, visited, recStack)) {
                return true;
            } else if (recStack[w]) {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

vector<int> Graph::round(int v, int w) {
    vector<int> path;
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> parent(V, -1);

    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < adjList[curr].size(); i++) {
            int next = adjList[curr][i].first;
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    if (parent[w] == -1) {
        cout << "不存在路径" << endl;
        return path;
    }

    int curr = w;
    while (curr != v) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int, pair<int, int>>> Graph::KruskalMST() {
    vector<pair<int, pair<int, int>>> result;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            edges.push_back(make_pair(adjList[i][j].second, make_pair(i, adjList[i][j].first)));
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(V);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int count = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;

        int set_u = parent[u];
        int set_v = parent[v];

        if (set_u != set_v) {
            count++;
            result.push_back(make_pair(weight, make_pair(u, v)));

            for (int j = 0; j < V; j++) {
                if (parent[j] == set_v) {
                    parent[j] = set_u;
                }
            }
        }

        if (count == V - 1) {
            break;
        }
    }

    return result;
}

void Graph::printMST() {
    vector<pair<int, pair<int, int>>> MST = KruskalMST();

    cout << "最小生成树的边为：" << endl;
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].second.first << " -- " << MST[i].second.second << " : " << MST[i].first << endl;
    }
}

vector<int> Graph::findHamiltonianCycle() {
    vector<int> path;
    vector<bool> visited(V, false);

    path.push_back(0);
    visited[0] = true;

    if (findHamiltonianCycleUtil(0, visited, path, 1)) {
        return path;
    } else {
        return vector<int>{};
    }
}

bool Graph::findHamiltonianCycleUtil(int v, vector<bool>& visited, vector<int>& path, int count) {
    if (count == V) {
        int lastVertex = path[path.size() - 1];
        int firstVertex = path[0];
        for (int i = 0; i < adjList[lastVertex].size(); i++) {
            if (adjList[lastVertex][i].first == firstVertex) {
                path.push_back(firstVertex);
                return true;
            }
        }
        return false;
    }

    for (int i = 0; i < adjList[v].size(); i++) {
        int w = adjList[v][i].first;
        if (!visited[w]) {
            visited[w] = true;
            path.push_back(w);

            if (findHamiltonianCycleUtil(w, visited, path, count + 1)) {
                return true;
            }

            visited[w] = false;
            path.pop_back();
        }
    }

    return false;
}

void Graph::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
        }
        cout << endl;
    }
}

void Graph::DFSUtil(int v, vector<bool>& visited, vector<int>& result) {
    visited[v] = true;
    result.push_back(v);

    for (int i = 0; i < adjList[v].size(); i++) {
        int w = adjList[v][i].first;
        if (!visited[w]) {
            DFSUtil(w, visited, result);
        }
    }
}
