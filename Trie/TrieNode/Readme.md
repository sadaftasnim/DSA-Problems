This file defines the `TrieNode` class, which represents a single node in a **Trie data structure**. The `TrieNode` class is used to build the nodes of the Trie, where each node stores a character and has pointers to its child nodes.

---

## Overview

The `TrieNode` class is a fundamental building block for the Trie. Each node contains the following attributes:

- **data**: Stores the character associated with the node.
- **children**: An array of pointers, where each pointer corresponds to a child node for a specific character ('a' to 'z').
- **isTerminal**: A boolean flag indicating whether the current node represents the end of a word.

---

## Class Definition

### 1. `TrieNode`

The `TrieNode` class has the following attributes and methods:

- **Attributes**:
  - `data`: A character representing the node's data (a single alphabet character).
  - `children`: A pointer to an array of `TrieNode*` for the 26 lowercase English alphabet characters. Each index (0-25) corresponds to a letter from 'a' to 'z'.
  - `isTerminal`: A boolean flag (`false` by default) indicating whether the node is the end of a word.

- **Constructor**:
  - `TrieNode(char data)`: Initializes the `data` attribute with the given character and allocates memory for the `children` array. The `children` array is initialized to `nullptr` for all 26 positions. The `isTerminal` flag is set to `false` by default.
