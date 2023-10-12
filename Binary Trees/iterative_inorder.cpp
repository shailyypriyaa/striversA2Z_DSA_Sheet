#include<iostream>
#include<vector>
#include<stack>
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
vector<int> inorderTraversal(TreeNode* root) 
{
    // Create a vector to store the result of the inorder traversal.
    vector<int> inOrder;

    // Create a stack for iterative traversal.
    stack<TreeNode*> s;

    while (true) {
        if (root != NULL) {
            // 1. If the current node is not NULL, push it onto the stack and move to its left child.
            s.push(root);
            root = root->left;
        } else {
            // 2. If the current node is NULL, and the stack is not empty, pop the top node from the stack.
            if (s.empty())
                break;
            root = s.top();
            s.pop();

            // 3. Visit the current node and add its value to the inOrder vector.
            inOrder.push_back(root->val);

            // 4. Move to the right child of the current node.
            root = root->right;
        }
    }

    // Return the vector containing the inorder traversal result.
    return inOrder;
}
