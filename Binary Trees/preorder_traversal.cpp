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
 
void preorder(TreeNode *root, vector<int> &preTree)
{
    // Base case: If the current node is NULL, return and continue to the parent node.
    if (root == NULL)
        return;

    // 1. Visit the current node and add its value to the preTree vector.
    preTree.push_back(root->val);

    // 2. Recursively traverse the left subtree, visiting left child nodes.
    preorder(root->left, preTree);

    // 3. Recursively traverse the right subtree, visiting right child nodes.
    preorder(root->right, preTree);
}

vector<int> preorderTraversal(TreeNode* root) 
{
    // Create a vector to store the result of the preorder traversal.
    vector<int> preTree;

    // Start the preorder traversal from the root node, passing the result vector.
    preorder(root, preTree);

    // Return the vector containing the preorder traversal result.
    return preTree;
}
