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

vector<vector<int>> levelOrder(TreeNode* root) 
{
    // Create a 2D vector to store the result of the level order traversal.
    vector<vector<int>> ans;

    // Check if the tree is empty. If so, return an empty result.
    if (root == NULL)
        return ans;

    // Create a queue to perform level order traversal.
    queue<TreeNode*> q;

    // Start with the root node as the first level.
    q.push(root);

    // Continue traversal while the queue is not empty.
    while (!q.empty())
    {
        // Get the number of nodes at the current level.
        int s = q.size();

        // Create a vector to store the values at the current level.
        vector<int> v;

        // Process all nodes at the current level.
        for (int i = 0; i < s; i++)
        {
            // Dequeue the front node.
            TreeNode* node = q.front();
            q.pop();

            // Enqueue the left and right child nodes, if they exist.
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            // Add the value of the current node to the current level vector.
            v.push_back(node->val);
        }

        // Add the vector of values for the current level to the result.
        ans.push_back(v);
    }

    // Return the 2D vector containing the level order traversal result.
    return ans;
}
