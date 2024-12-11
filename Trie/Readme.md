# Trie Data Structure Implementation

This project provides an implementation of a **Trie data structure** in C++ for basic operations like insertion, searching, and deletion of words. The code includes three files:

1. `Trie_use.cpp`: The main file to test the Trie operations.
2. `Trie.h`: The implementation of the Trie class.
3. `TrieNode.h`: The implementation of the TrieNode class.

---

## Features
- **Insertion**: Add words to the Trie.
- **Search**: Check if a word exists in the Trie.
- **Deletion**: Remove words from the Trie while ensuring efficient memory management.

---

## File Descriptions

### 1. TrieNode.h
This file defines the `TrieNode` class, which represents a single node in the Trie.  
**Key Features:**
- `data`: Stores the character at the node.
- `children`: An array of pointers for the next characters (26 for lowercase English alphabets).
- `isTerminal`: A boolean indicating if the node represents the end of a word.

### 2. Trie.h
This file defines the `Trie` class and its methods for operating on the Trie.  
**Key Methods:**
- `insertWord`: Adds a word to the Trie.
- `searchWord`: Checks if a word exists in the Trie.
- `removeWord`: Deletes a word from the Trie.

### 3. Trie_use.cpp
This file contains the `main` function to test the Trie operations. It demonstrates:
1. Inserting words into the Trie.
2. Searching for words.
3. Removing words from the Trie.



