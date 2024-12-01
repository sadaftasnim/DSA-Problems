# Path from Source to Destination in a Binary Tree

This project implements a C++ program to find the path between two nodes in a binary tree. The algorithm identifies the Lowest Common Ancestor (LCA) of the two nodes and constructs the path from the source node to the destination node.

## How It Works

1. **Find Path to Nodes**:
   - The program finds the path from the root of the tree to the `source` and `destination` nodes.

2. **Identify the LCA**:
   - The LCA is determined as the last common node in the paths from the root to the two nodes.

3. **Construct the Path**:
   - Combines the path from the source to the LCA and the LCA to the destination.

## Input Example

The binary tree is hardcoded as:

        1
      /   \
     2     3
    / \   / \
   4   5 6   7



Example inputs:
- `source = 4`
- `destination = 7`

Expected output:

Path from 4 to 7: 4 2 1 3 7

