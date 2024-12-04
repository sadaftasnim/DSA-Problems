# Kruskal's Algorithm Implementation in C++

## Overview

This program implements **Kruskal's Algorithm** to find the **Minimum Spanning Tree (MST)** of a connected, undirected graph. Kruskal's Algorithm builds the MST by adding the smallest edges to the tree while ensuring no cycles are formed.

---

## Features

1. **Minimum Spanning Tree (MST)**:
   - Finds the MST with the smallest total edge weight.
   - Works for connected, undirected graphs.

2. **Union-Find Technique**:
   - Efficiently detects cycles using a **disjoint-set** structure.

3. **Edge Weight Sorting**:
   - Sorts edges by weight to process the smallest edges first.

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
1. **`compare`**:
   - Comparator function for sorting edges by weight in ascending order.

2. **`findParent`**:
   - Implements the **union-find** technique to detect cycles.

3. **`kruskals`**:
   - Main function implementing Kruskal's Algorithm:
     - Sorts edges by weight.
     - Iteratively adds edges to the MST, ensuring no cycles are formed.
     - Uses the union-find technique to merge sets.

---

## How to Use

### Input Format
1. First line: Number of vertices (`v`) and edges (`e`).
2. Next `e` lines: Each line contains three integers:
   - Two vertices (`source`, `dest`) connected by the edge.
   - Weight of the edge (`weight`).

### Example Input
```plaintext
6 11
1 3 1
0 3 3
4 5 5
3 5 7
2 4 9
3 4 11
2 5 10
2 1 8
0 2 4
0 1 2
2 3 6

Example Output

1 3 1
0 1 2
0 2 4
4 5 5
3 5 7
