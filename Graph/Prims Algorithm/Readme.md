# Prim's Algorithm - Minimum Spanning Tree

## Description

Prim's Algorithm is a greedy algorithm used to find the **Minimum Spanning Tree (MST)** of a graph. The MST is a subset of the edges that connects all the vertices of the graph with the minimum total edge weight and no cycles.

This implementation of Prim's Algorithm uses a **Min-Heap** (priority queue) to efficiently pick the edge with the smallest weight at each step. It also uses a **visited array** to ensure that each vertex is added only once to the MST.

---

## Key Features

- **Time Complexity**: O(E * log V)  
  Where `E` is the number of edges and `V` is the number of vertices in the graph.
- **Data Structure Used**: Min-Heap (priority queue) and Visited Array.
- **Graph Type**: Undirected, weighted graph.

---

## Algorithm Steps

1. **Initialize**:
   - Create a Min-Heap to store the edges.
   - Use a visited array to track which vertices have already been added to the MST.
   - Start with an arbitrary vertex (we use vertex 1 in this implementation).

2. **Main Loop**:
   - Extract the edge with the smallest weight from the Min-Heap.
   - If the vertex has already been added to the MST (visited), skip it.
   - Otherwise, add the vertex to the MST and mark it as visited.
   - Push all unvisited adjacent vertices to the Min-Heap.

3. **Repeat** until all vertices are included in the MST.

4. **Output**:
   - The total weight of the MST.