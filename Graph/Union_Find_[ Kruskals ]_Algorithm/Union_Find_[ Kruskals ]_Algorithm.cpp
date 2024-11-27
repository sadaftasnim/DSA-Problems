#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for an edge with weight
struct Edge {
    int u, v, weight;

    // Comparison operator to sort edges by weight
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

// Define a structure for storing output of the union operation
struct Output {
    int u, v, weight;
    string message;

    Output(int _u, int _v, int _weight, string _message) 
        : u(_u), v(_v), weight(_weight), message(_message) {}
};

// Your provided find method (no recursion)
int find(int x, vector<int>& parent) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

// Your provided union method
bool unionSets(int x, int y, vector<int>& parent) {
    int root_X = find(x, parent);
    int root_Y = find(y, parent);

    if (root_X != root_Y) {
        parent[root_X] = root_Y; // Merge the sets
        return true;  // Edge added
    }
    return false;  // Edge already connects the same set
}

int main() {
    int n = 5; // Number of vertices (0 to 4)

    // Create the parent vector inside the main function
    vector<int> parent(n);

    // Initialize each element to be its own parent
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // Define the weighted edges of the graph
    vector<Edge> edges = {
        {0, 1, 10}, // Edge from 0 to 1 with weight 10
        {1, 2, 20}, // Edge from 1 to 2 with weight 20
        {2, 3, 30}, // Edge from 2 to 3 with weight 30
        {3, 4, 40}, // Edge from 3 to 4 with weight 40
        {0, 3, 50}, // Edge from 0 to 3 with weight 50
        {1, 4, 60}  // Edge from 1 to 4 with weight 60
    };

    // Sort edges based on their weights
    sort(edges.begin(), edges.end());

    // Create an array to store output
    vector<Output> output_array;

    // Apply union operation for each sorted edge
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        bool isAdded = unionSets(u, v, parent); // Perform union

        // Store the result in the output_array
        if (isAdded) {
            output_array.push_back(Output(u, v, weight, "added. Nodes connected."));
        } else {
            output_array.push_back(Output(u, v, weight, "already connects the same set."));
        }
    }

    // Display the output_array
    for (const auto& output : output_array) {
        cout << "Edge (" << output.u << ", " << output.v << ") with weight " << output.weight 
             << " " << output.message << endl;
    }

    return 0;
}
