# Approach 1: DFS with Visited and Color Arrays

This approach uses **Depth First Search (DFS)** to determine if a graph can be colored in two colors such that no two adjacent nodes share the same color. The graph is considered **bipartite** if it can be divided into two sets with no edges within the same set.

### Step-by-Step Explanation

#### Data Structures:
- **`color[]` array**: Tracks the color assigned to each node. Initially, all nodes are uncolored (`-1`).
- **`visited[]` array**: Tracks whether a node has been visited during the DFS traversal. This prevents revisiting nodes and helps in detecting cycles.

#### DFS Function: `dfs(int source, int clr, vector<vector<int>>& graph, vector<int>& visited, vector<int>& color)`
- **`source`**: The current node being visited.
- **`clr`**: The color that should be assigned to the current node (either 0 or 1).

##### Process:
1. Mark the `source` node as visited and assign it the color `clr`.
2. For each **neighbor** of the `source` node:
   - If the neighbor has **not been visited**, color it with the opposite color (using `!clr`, which toggles between 0 and 1).
     - Recursively call DFS for this neighbor.
   - If the neighbor has been visited and its color is **the same** as the `source`, return `false` because it violates the bipartite condition (two adjacent nodes must not have the same color).

#### Main Function: `isBipartite(vector<vector<int>>& graph)`
1. Initialize the `color[]` and `visited[]` arrays.
2. For each node in the graph:
   - If the node hasn’t been visited, start a DFS from that node with color `0` (you can start with either color).
   - If DFS returns `false` at any point, it means the graph is **not bipartite**, so return `false`.
3. If DFS completes without finding any issues, return `true`, meaning the graph is bipartite.

---

# Approach 2: DFS Without Visited Array

This approach is similar to the first one but does **not explicitly use a `visited[]` array**. Instead, it relies on the `color[]` array to track whether a node has been visited or not.

### Step-by-Step Explanation

#### Data Structures:
- **`color[]` array**: Tracks the color of each node. If a node is uncolored, its value is `-1`.

#### DFS Function: `dfs(int source, vector<vector<int>>& graph, vector<int>& color)`
- **`source`**: The current node being visited.

##### Process:
1. For each **neighbor** of the `source` node:
   - If the neighbor is **uncolored** (`color[neighbor] == -1`), assign it the opposite color of the `source` node (using `1 ^ color[source]` to toggle between 0 and 1).
     - Recursively call DFS for this neighbor.
   - If the neighbor has been **colored** and its color is the same as the `source`, return `false` because it violates the bipartite condition.

#### Main Function: `isBipartite(vector<vector<int>>& graph)`
1. Initialize the `color[]` array.
2. Start DFS from any node (you can start with node 0).
3. For each node:
   - If it’s uncolored, treat it as the starting point for a new DFS.
   - If DFS returns `false` at any point, the graph is **not bipartite**, so return `false`.
4. If DFS completes without any issues, return `true`, indicating that the graph is bipartite.

