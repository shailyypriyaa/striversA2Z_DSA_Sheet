#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Define a global vector to store the result of the postorder traversal.
vector<int> res;

// Recursive function to perform a postorder traversal of a binary tree.
// The result is stored in the 'res' vector.
void postorder(TreeNode* &root)
{
    // Base case: If the current node is NULL, return and continue to the parent node.
    if (root == NULL)
        return;

    // 1. Recursively traverse the left subtree, visiting left child nodes.
    postorder(root->left);

    // 2. Recursively traverse the right subtree, visiting right child nodes.
    postorder(root->right);

    // 3. Visit the current node and add its value to the 'res' vector.
    res.push_back(root->val);
}

// Function to initiate the postorder traversal and return the result.
vector<int> postorderTraversal(TreeNode* root)
{
    // Start the postorder traversal from the root node, storing the result in 'res'.
    postorder(root);

    // Return the 'res' vector containing the postorder traversal result.
    return res;
}
