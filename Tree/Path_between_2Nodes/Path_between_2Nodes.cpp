#include <iostream>
#include <vector>
using namespace std;

// Definition of a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the path from root to a given node
bool findPath(Node* root, int key, vector<int>& path) {
    if (!root)
        return false;

    // Add the current node to the path
    path.push_back(root->data);

    // If the current node is the key, return true
    if (root->data == key)
        return true;

    // Recursively search in the left and right subtrees
    if ((root->left && findPath(root->left, key, path)) ||
        (root->right && findPath(root->right, key, path)))
        return true;

    // If not found in this path, remove the current node
    path.pop_back();
    return false;
}

// Function to find the path from source to destination in a general tree
vector<int> findPathFromSourceToDestination(Node* root, int source, int destination) {
    vector<int> path1, path2;

    // Find the paths from root to source and root to destination
    if (!findPath(root, source, path1) || !findPath(root, destination, path2)) {
        cout << "One of the nodes is not present in the tree.\n";
        return {};
    }

    // Find the Lowest Common Ancestor (LCA)
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
        i++;
    int lcaIndex = i - 1;  // Correctly identify the LCA index

    // Create the full path from source to destination
    vector<int> result;

    // Add the path from source to LCA (excluding LCA)
    for (int j = path1.size() - 1; j > lcaIndex; j--)
        result.push_back(path1[j]);

    // Add the path from LCA to destination (including LCA once)
    for (int j = lcaIndex; j < path2.size(); j++)
        result.push_back(path2[j]);

    return result;
}

// Driver function
int main() {
    // Create a general tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int source = 4, destination = 7;
    vector<int> path = findPathFromSourceToDestination(root, source, destination);

    if (!path.empty()) {
        cout << "Path from " << source << " to " << destination << ": ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
