#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to implement Dijkstra's Algorithm using a Min-Heap
void dijkstra(int source, const vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size(); // Number of vertices
    vector<int> distances(n, INT_MAX); // Distance array, initialized to infinity
    distances[source] = 0;

    // Min-Heap to store {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source}); // Push source with distance 0

    while (!minHeap.empty()) {
        int dist = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        // Process only if the current distance is up-to-date
        if (dist > distances[node]) continue;

        // Explore neighbors of the current node
        for (const auto& neighbor : adjList[node]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step: Check if a shorter path is found
            if (dist + weight < distances[next]) {
                distances[next] = dist + weight;
                minHeap.push({distances[next], next}); // Push updated distance to the min-heap
            }
        }
    }

    // Output the shortest distances
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }
}

int main() {
    int vertices = 6; // Number of vertices
    vector<vector<pair<int, int>>> adjList(vertices);

    // Adding edges to the adjacency list
    adjList[0].push_back({1, 4});
    adjList[0].push_back({2, 1});
    adjList[1].push_back({3, 1});
    adjList[2].push_back({1, 2});
    adjList[2].push_back({3, 5});
    adjList[3].push_back({4, 3});
    adjList[4].push_back({5, 2});
    adjList[3].push_back({5, 1});

    int source = 0; // Source vertex
    dijkstra(source, adjList);

    return 0;
}

/*
Example Output for Source Node 0:
--------------------------------
Shortest distances from source node 0:
Node 0: 0
Node 1: 3
Node 2: 1
Node 3: 4
Node 4: 7
Node 5: 5
*/
