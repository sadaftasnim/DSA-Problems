#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// Function to implement Prim's Algorithm
void primsAlgorithm(int n, vector<pair<int, int>> adj[]) {
    // Min-heap to store (weight, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Visited array to mark nodes included in MST
    vector<bool> visited(n, false);

    // Start from vertex 1 (can start from any node)
    minHeap.push({0, 1}); // {weight, vertex}

    int mstWeight = 0; // Total weight of MST

    while (!minHeap.empty()) {
        auto [weight, u] = minHeap.top(); // Get minimum weight edge
        minHeap.pop();

        // Skip if already visited
        if (visited[u]) continue;

        // Mark vertex as visited and include its weight in MST
        visited[u] = true;
        mstWeight += weight;

        // Traverse all adjacent vertices of 'u'
        for (auto &[v, w] : adj[u]) {
            if (!visited[v]) {
                minHeap.push({w, v});
            }
        }
    }

    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n]; // Adjacency list

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    primsAlgorithm(n, adj);

    return 0;
}
