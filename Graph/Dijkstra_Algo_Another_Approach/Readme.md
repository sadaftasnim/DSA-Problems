# Dijkstra's Algorithm Implementation in C++

## Overview

This program implements **Dijkstra's Algorithm** to find the shortest path from a starting node (node `0`) to all other nodes in a graph with non-negative edge weights. It uses an adjacency matrix for graph representation and is suitable for small to medium-sized graphs.

---

## Features

1. **Shortest Path Calculation**:
   - Computes the shortest path from a single source (vertex `0`) to all other vertices.
   - Handles weighted, undirected graphs with non-negative weights.

2. **Dynamic Memory Management**:
   - Efficient use of dynamic memory for adjacency matrix representation of the graph.

3. **Custom Input**:
   - Allows users to define the graph structure by specifying vertices, edges, and weights.

---

## Code Explanation

### Input
1. Number of vertices (`v`) and edges (`e`).
2. For each edge:
   - Two vertices (`f` and `s`) connected by the edge.
   - Weight of the edge (`weight`).

### Graph Representation
- The graph is represented using an adjacency matrix `edges[v][v]`, where:
  - `edges[i][j]` contains the weight of the edge between vertices `i` and `j`.
  - `edges[i][j] = 0` indicates no edge between `i` and `j`.

### Output
- The shortest distance from the source node (`0`) to each vertex.

### Key Functions
1. **`findMinVertex`**:
   - Finds the unvisited vertex with the smallest distance from the source.
   - Used in each iteration of the algorithm to process the next closest vertex.

2. **`dijkstra`**:
   - Core function implementing Dijkstra's algorithm.
   - Uses `findMinVertex` to iteratively relax edges and update shortest distances.

---

## How to Use

### Input Format
1. First line: Number of vertices (`v`) and edges (`e`).
2. Next `e` lines: Each line contains three integers:
   - Two vertices (`f`, `s`) connected by the edge.
   - Weight of the edge (`weight`).

### Example Input
```plaintext
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 4

Example Output

0 0
1 4
2 6
3 9
4 13
