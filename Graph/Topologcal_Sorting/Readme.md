# Topological Sort Using BFS

This program implements **Topological Sorting** using **Kahn's Algorithm** (BFS approach) in C++. 

## Algorithm Explanation

### Understand the Problem:
Topological sorting is a way to order the tasks (nodes) in a directed graph such that for every task that depends on another, the dependent task comes later. This only works if the graph has no cycles (it's a Directed Acyclic Graph, or DAG).

### Step-by-Step Process:

1. **Calculate Dependencies (In-Degree):**
   - For each task (node), count how many other tasks must be completed before it (the "in-degree").
   - Example: If task 3 depends on task 2, task 3's in-degree is incremented.

2. **Find Independent Tasks:**
   - Add all tasks with no dependencies (in-degree of 0) to a queue. These tasks can be done immediately.

3. **Process Tasks in Order:**
   - While the queue is not empty:
     - Remove a task from the queue.
     - Add it to the result (the topological order).
     - For each task that depends on the current task, reduce its in-degree by 1 (because its dependency has been completed).
     - If a dependent task's in-degree becomes 0, add it to the queue.

4. **Check for Cycles:**
   - If some tasks are left unprocessed (in-degree never became 0), it means there’s a cycle in the graph, and topological sorting is not possible.

5. **Output the Result:**
   - The order of tasks in the result is the topological sort. If a cycle exists, notify that sorting isn’t possible.
