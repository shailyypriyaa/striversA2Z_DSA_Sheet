#include<iostream>
#include<vector>
#include<climits>
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
    // Recursive function to find the maximum path sum for a given node.
    int findMaxPathSum(TreeNode *root, int &maxi) {
        if (!root)
            return 0;

        // Calculate the maximum path sum for the left subtree, considering only positive values.
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));

        // Calculate the maximum path sum for the right subtree, considering only positive values.
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        int value = root->val; // The value of the current node.

        // Update 'maxi' to store the maximum path sum found, considering both left and right subtrees.
        maxi = max(maxi, (leftMaxPath + rightMaxPath) + value);

        // Return the maximum path sum starting at the current node. This is the path that can be extended to its parent.
        return max(leftMaxPath, rightMaxPath) + value;

        // The logic above calculates the maximum path sum considering both left and right subtrees,
        // and ensures that we don't consider negative values in the path. We then return the maximum
        // path sum that can be extended to the parent node, and update 'maxi' with the maximum path sum.
    }

    // Function to find the maximum path sum in the binary tree.
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Initialize 'maxi' to a minimum value.
        findMaxPathSum(root, maxi); // Call the helper function to find the maximum path sum.
        return maxi; // Return the maximum path sum found.
    }
};
