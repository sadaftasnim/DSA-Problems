This file defines the `Trie` class, which implements the **Trie data structure** in C++ for efficient word insertion, searching, and deletion operations.

---

## Overview

The `Trie` class in this file provides the following operations:

- **Insertion**: Adds words to the Trie.
- **Search**: Checks if a word exists in the Trie.
- **Deletion**: Removes a word from the Trie while managing memory efficiently.

---

## Class Definitions

### 1. `TrieNode` (in `TrieNode.h`)

Each `Trie` instance relies on the `TrieNode` class, which represents a single node in the Trie. Each `TrieNode` has the following attributes:
- `data`: Stores the character at the current node.
- `children`: An array of 26 pointers for each possible character ('a' to 'z').
- `isTerminal`: A boolean flag that marks whether a node represents the end of a word.

### 2. `Trie`

The `Trie` class provides the methods to interact with the Trie structure:

- **Constructor**:
  - `Trie()`: Initializes the Trie by creating the root node as a `TrieNode` with a null character (`'\0'`).

- **Methods**:

  - **`insertWord(string word)`**:
    - Inserts a word into the Trie. This method calls the helper function to recursively insert characters in the Trie.
  
  - **`insertWord(TrieNode* root, string word)`** (helper function):
    - This helper function recursively traverses the Trie, creating new nodes as necessary and marking the end of a word.
  
  - **`searchWord(string word)`**:
    - Checks if a word exists in the Trie. This method uses a recursive helper to traverse the Trie.
  
  - **`searchWord(TrieNode* root, string word)`** (helper function):
    - This helper function is used to check if a word is present by recursively searching for each character in the Trie.

  - **`removeWord(string word)`**:
    - Deletes a word from the Trie. It recursively marks the end of the word as false and cleans up unused nodes.
  
  - **`removeWord(TrieNode* root, string word)`** (helper function):
    - This helper function performs the actual deletion of the word and its unused nodes.

