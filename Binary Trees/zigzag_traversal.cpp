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
class Solution {
public:
    // Function to perform a zigzag level order traversal of a binary tree.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; // Initialize the result vector to store the traversal.

        if (root == NULL) return res; // If the tree is empty, return an empty result.

        queue<TreeNode*> q; // Create a queue for level-order traversal.
        q.push(root); // Start with the root node.
        bool leftToRight = true; // Flag to indicate the current direction of traversal.

        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level.
            vector<int> ans(size); // Create a vector to store the values at the current level.

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Calculate the index based on the current traversal direction.
                int index = leftToRight ? i : (size - 1 - i);

                ans[index] = temp->val; // Store the value of the current node.

                if (temp->left) {
                    q.push(temp->left); // Enqueue the left child if it exists.
                }

                if (temp->right) {
                    q.push(temp->right); // Enqueue the right child if it exists.
                }
            }

            leftToRight = !leftToRight; // Toggle the traversal direction for the next level.
            res.push_back(ans); // Add the values at the current level to the result vector.
        }

        return res; // Return the result of the zigzag level order traversal.
    }
};
