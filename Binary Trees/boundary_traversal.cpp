#include<iostream>
#include<vector>
using namespace std;
template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
bool isLeaf(TreeNode<int> *root) {
    // Function to check if a given node is a leaf node.
    if ((root->left == NULL) && (root->right == NULL))
        return true; // If both left and right children are NULL, it's a leaf node.
    else
        return false; // Otherwise, it's not a leaf node.
}

void addLeftBoundary(TreeNode<int> *root, vector<int>& res) {
    // Function to add the left boundary nodes to the result vector.
    TreeNode<int> *curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->data); // Add the non-leaf node to the result.
        if (curr->left)
            curr = curr->left; // Traverse left if it exists.
        else
            curr = curr->right; // Otherwise, traverse right.
    }
}

void addLeaves(TreeNode<int> *root, vector<int>& res) {
    // Function to add the leaf nodes to the result vector.
    if (isLeaf(root)) {
        res.push_back(root->data); // Add the current leaf node to the result.
        return;
    }
    if (root->left)
        addLeaves(root->left, res); // Recursively add leaves from the left subtree.
    if (root->right)
        addLeaves(root->right, res); // Recursively add leaves from the right subtree.
}

void addRightBoundary(TreeNode<int> *root, vector<int>& res) {
    // Function to add the right boundary nodes to the result vector.
    TreeNode<int> *curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->data); // Add the non-leaf node to a temporary vector.
        if (curr->right)
            curr = curr->right; // Traverse right if it exists.
        else
            curr = curr->left; // Otherwise, traverse left.
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]); // Add the non-leaf nodes from the temporary vector in reverse order.
    }
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    // Function to traverse the boundary of a binary tree and return the result.
    vector<int> res;
    if (!root) return res; // If the tree is empty, return an empty result.

    if (!isLeaf(root)) res.push_back(root->data); // Add the root if it's not a leaf node.

    addLeftBoundary(root, res); // Add the left boundary nodes.
    addLeaves(root, res); // Add the leaf nodes.
    addRightBoundary(root, res); // Add the right boundary nodes.

    return res; // Return the result containing the boundary nodes.
}
