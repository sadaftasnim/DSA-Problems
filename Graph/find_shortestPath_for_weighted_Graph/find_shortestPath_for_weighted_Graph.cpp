#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to find the shortest path using BFS in the transformed graph
int shortestDistance(int source, int destination, unordered_map<int, vector<int>>& adjList) {
    queue<int> q;
    unordered_map<int, int> distance; // Distance from source to each node

    q.push(source);
    distance[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adjList[node]) {
            if (distance.find(neighbor) == distance.end()) { // If not visited
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (neighbor == destination) {
                    return distance[neighbor]; // Shortest path found
                }
            }
        }
    }

    return -1; // No path found
}

int main() {
    int nextNode = 7; // Start dummy nodes from 7 (assuming original nodes are 1-6)
    unordered_map<int, vector<int>> adjList;

    // Adding edges and transforming weights into dummy nodes
    vector<tuple<int, int, int>> edges = {
        {1, 2, 2},
        {1, 4, 2},
        {2, 3, 3},
        {2, 4, 2},
        {3, 4, 2},
        {3, 5, 2},
        {3, 6, 2},
        {4, 5, 1},
        {5, 6, 1}
    };

    for (auto [u, v, w] : edges) {
        if (w == 1) {
            adjList[u].push_back(v); // Direct edge for weight 1
        } else {
            int prev = u;
            for (int i = 1; i < w; i++) {
                adjList[prev].push_back(nextNode);
                prev = nextNode;
                nextNode++;
            }
            adjList[prev].push_back(v); // Connect last dummy node to the destination
        }
    }

    int source = 1, destination = 6;
    int result = shortestDistance(source, destination, adjList);

    if (result == -1) {
        cout << "No path exists from " << source << " to " << destination << endl;
    } else {
        cout << "The shortest distance from " << source << " to " << destination << " is: " << result << endl;
    }

    return 0;
}





// -------------------------------------------------------------//
//using Vector of vector

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path using BFS in the transformed graph
int shortestDistance(int source, int destination, vector<vector<int>>& adjList) {
    queue<int> q;
    vector<int> distance(adjList.size(), -1); // Distance array initialized to -1 (unvisited)

    q.push(source);
    distance[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adjList[node]) {
            if (distance[neighbor] == -1) { // If not visited
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (neighbor == destination) {
                    return distance[neighbor]; // Shortest path found
                }
            }
        }
    }

    return -1; // No path found
}

int main() {
    int vertices = 6; // Original number of vertices
    int dummyNodesStart = vertices + 1; // Start of dummy nodes
    int maxNodes = 100; // Maximum number of nodes including dummy nodes (adjust as needed)

    vector<vector<int>> adjList(maxNodes); // Adjacency list with a fixed size

    // Adding edges and transforming weights into dummy nodes
    vector<tuple<int, int, int>> edges = {
        {1, 2, 2},
        {1, 4, 2},
        {2, 3, 3},
        {2, 4, 2},
        {3, 4, 2},
        {3, 5, 2},
        {3, 6, 2},
        {4, 5, 1},
        {5, 6, 1}
    };

    int nextNode = dummyNodesStart; // Start dummy nodes at the next available index

    for (auto [u, v, w] : edges) {
        if (w == 1) {
            adjList[u].push_back(v); // Direct edge for weight 1
        } else {
            int prev = u;
            for (int i = 1; i < w; i++) {
                adjList[prev].push_back(nextNode);
                prev = nextNode;
                nextNode++;
            }
            adjList[prev].push_back(v); // Connect last dummy node to the destination
        }
    }

    int source = 1, destination = 6;
    int result = shortestDistance(source, destination, adjList);

    if (result == -1) {
        cout << "No path exists from " << source << " to " << destination << endl;
    } else {
        cout << "The shortest distance from " << source << " to " << destination << " is: " << result << endl;
    }

    return 0;
}
