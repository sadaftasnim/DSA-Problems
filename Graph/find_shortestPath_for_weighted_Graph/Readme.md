# Shortest Path in Graph with Dummy Nodes

This project calculates the shortest path between two nodes in a graph with edge weights greater than 1 by transforming the graph. Edges with weights greater than 1 are split into multiple smaller edges using dummy nodes, and the shortest path is calculated using the Breadth-First Search (BFS) algorithm.

## Problem Description

The graph is transformed by introducing dummy nodes between edges that have weights greater than 1. The program calculates the shortest distance from a **source node** to a **destination node** using BFS. If no path exists, it returns `-1`.

### Key Features:

- **Graph Transformation**:
  - For edges with weight `1`, the edge is directly added to the adjacency list.
  - For edges with weight greater than `1`, the edge is split into smaller edges by introducing dummy nodes between them.

- **Breadth-First Search (BFS)**:
  - BFS is used to compute the shortest path between the source and destination.
  - The distance is tracked for each node during the BFS traversal.

- **Adjacency List Representation**:
  - The adjacency list is stored using a vector of vectors. This approach allows dynamic resizing and ensures the graph can accommodate any number of dummy nodes.

## Solution Approach

### 1. **Graph Transformation (Edge Decomposition)**:

Each edge in the graph is represented by a tuple `(source, destination, weight)`:

- For edges with weight `1`, they are directly added to the adjacency list.
- For edges with weight greater than `1`, they are split into multiple smaller edges by introducing dummy nodes.

### 2. **Breadth-First Search (BFS)**:

BFS is used to compute the shortest path from the **source node** to the **destination node**. It explores all neighbors and updates the distance array to track the shortest distance from the source.

### 3. **Calculating the Shortest Path**:

- BFS starts from the **source node** and explores the graph.
- The algorithm returns the shortest path distance from the source to the destination node.

## Example

Consider a graph with the following edges:

(1, 2, 2), (1, 4, 2), (2, 3, 3), (2, 4, 2), (3, 4, 2), (3, 5, 2), (3, 6, 2), (4, 5, 1), (5, 6, 1)

markdown
Copy code

For edges with weight greater than 1, they are transformed as follows:

- **(1, 2, 2)** is split into two edges with a dummy node.
- **(2, 3, 3)** is split into three edges with two dummy nodes.

After transforming the graph, the program computes the shortest path between the **source (1)** and the **destination (6)** using BFS.

## Code Structure

- **Adjacency List Representation**: 
  - The adjacency list is represented using a `vector<vector<int>>` where each index corresponds to a node, and the value is a list of neighbors.
  
- **Edge Processing**:
  - Edges with weight `1` are added directly.
  - Edges with weight greater than `1` are split into smaller edges with dummy nodes between them.

- **Breadth-First Search**:
  - The BFS algorithm computes the shortest path between the source node and the destination node.

## Example Run

1. **Input Graph** (with edge weights):
   - `(1, 2, 2), (1, 4, 2), (2, 3, 3), (2, 4, 2), (3, 4, 2), (3, 5, 2), (3, 6, 2), (4, 5, 1), (5, 6, 1)`
   
2. **Expected Output**:
   - Shortest distance from node 1 to node 6 after transforming edges.

### Steps:
- Transform edges with weight greater than `1` using dummy nodes.
- Use BFS to compute the shortest path from the source node to the destination.
