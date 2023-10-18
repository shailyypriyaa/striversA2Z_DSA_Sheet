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
class Solution {
public:
    int res = 0; // Initialize a class-level variable to store the result.

    // Function to calculate the height of a binary tree.
    int height(TreeNode* root) {
        if (!root)
            return 0; // If the root is null, the height is 0.

        // Recursively calculate the left and right subtree heights.
        int lh = height(root->left);
        int rh = height(root->right);

        // Update the 'res' variable to store the maximum diameter found.
        res = max(res, lh + rh + 1);

        // Return the height of the current subtree.
        return 1 + max(lh, rh);
    }

    // Function to calculate the diameter of a binary tree.
    int diameterOfBinaryTree(TreeNode* root) {
        int p = height(root); // Call the 'height' function to find the diameter.
        return res - 1; // Return the diameter, which is 'res' minus 1 (as per the problem definition).
    }
};
