# Graph Traversal: BFS and DFS in C++

## Overview

This program demonstrates **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** traversals on a graph. It supports disconnected graphs and uses an adjacency matrix for graph representation.

---

## Features

1. **DFS (Depth-First Search)**:
   - Explores as far as possible along each branch before backtracking.
   - Uses recursion and a `visited` array to avoid revisiting nodes.

2. **BFS (Breadth-First Search)**:
   - Explores all neighbors of a vertex before moving to the next level of neighbors.
   - Uses a queue and a `visited` array for traversal.

3. **Handles Disconnected Graphs**:
   - Both DFS and BFS ensure all connected components are traversed.

---

## Code Explanation

### Input
1. Number of vertices (`v`) and edges (`e`).
2. Pairs of vertices representing edges.

### Graph Representation
- An adjacency matrix (`edges[v][v]`) is used, where `edges[i][j] = 1` indicates an edge between vertex `i` and vertex `j`.

### Output
- DFS Traversal order.
- BFS Traversal order.

### Functions
1. **`dfs_print`**: Recursive function to perform DFS on the graph.
2. **`bfs_print`**: Iterative function using a queue to perform BFS.
3. **`dfs`**: Manages DFS traversal for all graph components.
4. **`bfs`**: Manages BFS traversal for all graph components.

---

## Code Usage

### Input Format
1. First line: Number of vertices `v` and edges `e`.
2. Next `e` lines: Each line contains two integers representing an edge between two vertices.

### Example Input
```plaintext
7 6
0 2
2 3
1 4
5 6
1 0
4 5

Example Output


DFS Traversal: 0 2 3 1 4 5 6
BFS Traversal: 0 2 3 1 4 5 6
