# Dijkstra's Algorithm Using Min-Heap in C++

## Overview

This program implements **Dijkstra's Algorithm** in C++ to find the shortest distances from a source node to all other nodes in a weighted graph. The algorithm uses a **Min-Heap** (priority queue) for efficient processing of nodes, ensuring optimal performance for graphs with non-negative edge weights.

---

## Features

- **Efficient Pathfinding**:
  - Utilizes a Min-Heap to retrieve the node with the smallest distance efficiently.
  - Processes only up-to-date distances using a validation check.

- **Graph Representation**:
  - The graph is stored as an **Adjacency List**, where each node points to a list of pairs representing its neighbors and edge weights.

- **Output**:
  - Displays the shortest distance from the source node to every other node.
  - Indicates nodes that are unreachable from the source.

---

## How It Works

1. **Initialization**:
   - All nodes are initialized with a distance of infinity (`INT_MAX`) except the source, which starts with a distance of 0.
   - A Min-Heap stores pairs of `{distance, node}`, starting with the source node.

2. **Processing Nodes**:
   - The algorithm extracts the node with the smallest distance from the Min-Heap.
   - It checks whether the extracted distance is still valid; outdated entries are skipped.

3. **Relaxation**:
   - For each neighbor of the current node, the algorithm checks if the path through the current node is shorter than the previously known path.
   - If a shorter path is found, the distance is updated, and the neighbor is pushed into the Min-Heap.

4. **Output**:
   - After all nodes are processed, the shortest distances from the source to every other node are displayed.