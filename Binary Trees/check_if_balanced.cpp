#include<iostream>
#include<vector>
#include<queue>
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

int dfsheight(TreeNode* root)
{
    // Base case: If the current node is NULL, its height is 0.
    if (root == NULL)
        return 0;

    // Calculate the height of the left subtree using recursion.
    int lh = dfsheight(root->left);

    // If the left subtree is unbalanced, propagate -1 upwards.
    if (lh == -1)
        return -1;

    // Calculate the height of the right subtree using recursion.
    int rh = dfsheight(root->right);

    // If the right subtree is unbalanced, propagate -1 upwards.
    if (rh == -1)
        return -1;

    // Check if the absolute difference in heights between left and right subtrees is greater than 1.
    // If it is, the tree is unbalanced, so propagate -1 upwards.
    if (abs(lh - rh) > 1)
        return -1;

    // Return the maximum height of the left and right subtrees, plus 1 for the current node.
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) 
{
    // Check if the height of the tree is -1, which indicates it's unbalanced.
    return dfsheight(root) != -1;
}
