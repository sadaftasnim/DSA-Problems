#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Topological Sort using BFS (Kahn's Algorithm)
vector<int> topologicalSort(int vertices, vector<vector<int>>& adjList) {
    vector<int> inDegree(vertices, 0); // Stores in-degrees of all vertices

    // Calculate in-degrees
    for (int i = 0; i < vertices; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q; // Queue for BFS
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i); // Add nodes with in-degree 0 to the queue
        }
    }

    vector<int> topoOrder; // To store the topological order

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Decrease the in-degree of neighbors
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor); // If in-degree becomes 0, add to queue
            }
        }
    }

    // Check if topological sorting is possible
    if (topoOrder.size() != vertices) {
        cout << "The graph is not a DAG. Topological sort not possible." << endl;
        return {};
    }

    return topoOrder;
}

int main() {
    int vertices = 6; // Number of vertices
    vector<vector<int>> adjList(vertices);

    // Create the graph (adjacency list representation)
    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    vector<int> result = topologicalSort(vertices, adjList);

    if (!result.empty()) {
        cout << "Topological Sort: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
