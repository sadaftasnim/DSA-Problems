# Maximum Number of Edges to be Added to a Tree to Keep It a Bipartite Graph

A **tree** is always a **bipartite graph** because we can always divide it into two disjoint sets where adjacent nodes are colored with different colors. This is essentially achieved by coloring the tree with two colors such that nodes at alternate levels have the same color.

### Problem Description:
The task is to compute the maximum number of edges that can be added to a tree while ensuring it stays a **bipartite graph**.

### Key Insights:
1. **Tree Properties**: 
   - A tree with `n` nodes always has `n-1` edges.
   - Since a tree is already a bipartite graph, we need to check how many additional edges can be added while maintaining this bipartite property.
   
2. **Bipartite Graph Properties**:
   - In a bipartite graph, nodes can be divided into two sets (`Set 0` and `Set 1`), with edges only connecting nodes from `Set 0` to `Set 1` (no edges within the same set).
   - The maximum number of edges that a bipartite graph with two sets of sizes `count_color0` and `count_color1` can have is:  
     **`count_color0 * count_color1`**.

3. **Solution Approach**:
   - **Step 1**: Perform a **DFS** (or **BFS**) traversal on the tree to color it with two colors and simultaneously count how many nodes are in each set:
     - `count_color0`: The number of nodes colored with color 0.
     - `count_color1`: The number of nodes colored with color 1.
   
   - **Step 2**: The maximum number of edges that can exist between the two sets in a bipartite graph is:  
     **`count_color0 * count_color1`**.
   
   - **Step 3**: The tree with `n` nodes already has `n-1` edges. Therefore, the maximum number of additional edges that can be added without violating the bipartite property is:  
     **`count_color0 * count_color1 - (n - 1)`**.

### Step-by-Step Explanation

1. **DFS/BFS Traversal**:
   - Start from any node and perform DFS/BFS.
   - Assign one color to the starting node and alternate the colors for each adjacent node.
   - Keep track of how many nodes are assigned to each color (`count_color0` and `count_color1`).

2. **Calculate Maximum Additional Edges**:
   - The number of edges that can be added to a bipartite graph is the product of the sizes of the two sets: `count_color0 * count_color1`.
   - The tree already has `n-1` edges, so the maximum number of additional edges is:  
     **`count_color0 * count_color1 - (n - 1)`**.


### Example:
Let’s consider an example to illustrate:

- Suppose we have a tree with 6 nodes and the traversal yields the following color counts:
  - `count_color0 = 3`
  - `count_color1 = 3`
  
  The maximum number of edges in a bipartite graph with these two sets is:
  ```text
  count_color0 * count_color1 = 3 * 3 = 9
