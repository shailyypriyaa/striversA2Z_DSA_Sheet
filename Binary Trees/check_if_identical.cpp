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
    // Function to check if two binary trees are the same.
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, they are considered the same.
        if (p == NULL && q == NULL) {
            return true;
        }
        // If one node is NULL and the other is not, they are not the same.
        if (p == NULL || q == NULL) {
            return false;
        }
        // If the values of the current nodes match, recursively check the left and right subtrees.
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        // If the values of the current nodes do not match, they are not the same.
        return false;
    }
};
