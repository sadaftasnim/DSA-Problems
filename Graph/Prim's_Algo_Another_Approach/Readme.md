# Prim's Algorithm Implementation in C++

## Overview

This program implements **Prim's Algorithm** to find the **Minimum Spanning Tree (MST)** of a connected, undirected graph. Prim's Algorithm grows the MST by adding the smallest edge that connects a visited vertex to an unvisited vertex.

---

## Features

1. **Minimum Spanning Tree (MST)**:
   - Finds the MST with the smallest total edge weight.
   - Works for connected, undirected graphs.

2. **Priority-based Selection**:
   - Uses a helper function to find the vertex with the smallest weight that hasn't been visited.

---

## Code Explanation

### Input
1. Number of vertices (`v`) and edges (`e`).
2. For each edge:
   - Two vertices (`source`, `dest`) connected by the edge.
   - Weight of the edge (`weight`).

### Output
- The edges of the MST in increasing order of vertices, along with their weights.

### Key Functions
1. **`findMinVertex`**:
   - Helper function to find the vertex with the smallest weight that hasn't been visited.

2. **`prims`**:
   - Main function implementing Prim's Algorithm:
     - Starts from an arbitrary vertex (vertex `0`).
     - Grows the MST by iteratively adding the smallest edge connecting the MST to an unvisited vertex.

---

## How to Use

### Input Format
1. First line: Number of vertices (`v`) and edges (`e`).
2. Next `e` lines: Each line contains three integers:
   - Two vertices (`source`, `dest`) connected by the edge.
   - Weight of the edge (`weight`).

### Example Input
```plaintext
5 7
0 1 2
0 3 6
1 3 8
1 2 3
1 4 5
2 4 7
3 4 9

Example Output
0 1 2
1 2 3
0 3 6
1 4 5
