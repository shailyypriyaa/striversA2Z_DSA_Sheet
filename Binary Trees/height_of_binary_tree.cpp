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

int maxDepth(TreeNode* root) 
{
    // Base case: If the current node is NULL, the depth is 0.
    if (!root)
    {
        return 0;
    }
    else
    {
        // Recursive case:
        // 1. Find the maximum depth of the left subtree.
        int leftDepth = maxDepth(root->left);

        // 2. Find the maximum depth of the right subtree.
        int rightDepth = maxDepth(root->right);

        // 3. Return the maximum depth among the left and right subtrees, plus 1 for the current node.
        return max(leftDepth, rightDepth) + 1;
    }   
}
