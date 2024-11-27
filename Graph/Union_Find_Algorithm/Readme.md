# Union-Find Algorithm

## Problem Description

The goal of this program is to implement the **Union-Find** (or **Disjoint Set Union - DSU**) algorithm to manage connected components of a graph. The Union-Find algorithm helps to efficiently check if two elements are part of the same set and also allows merging different sets.

The **Union-Find** algorithm is widely used in scenarios where we need to manage a collection of disjoint sets, and perform the following operations:

1. **Find**: Determine which set a particular element belongs to. This operation helps in checking if two elements are part of the same set.
2. **Union**: Merge two sets into a single set. This operation is used when we know two elements belong to different sets and we want to combine them.

---

## Algorithm Description

### Step 1: Define the Data Structures

- **Edge Structure**: We define a structure `Edge` that holds the two vertices of the edge (`u`, `v`) and its weight (`weight`).
- **Output Structure**: We define a structure `Output` to store the results of each edge operation, which includes the two vertices, the edge weight, and a message indicating whether the edge was added or skipped.

### Step 2: Initializing the Union-Find Data Structure

- Create a `parent` array to represent the disjoint sets. Initially, each vertex is its own parent (each vertex is in its own set).
- **`find(x)` function**: This function returns the representative (root) of the set that contains vertex `x`. It uses path compression to make the trees flatter and speeds up future operations.
- **`unionSets(x, y)` function**: This function merges the sets of vertices `x` and `y` if they are in different sets. It returns `true` if the sets are merged, otherwise `false`.

### Step 3: Processing the Edges

- For each edge `(u, v)` in the edge list:
  - Use the `find` function to check if `u` and `v` are in different sets (disjoint sets).
  - If they are in different sets, call `unionSets(u, v)` to merge the sets.
  - If they are in the same set, skip the edge to avoid creating cycles.

### Step 4: Display the Results

- Print the results stored in the `Output` array, showing the status of each edge:
  - If the edge was added, print "added. Nodes connected."
  - If the edge already connects the same set, print "already connects the same set."

