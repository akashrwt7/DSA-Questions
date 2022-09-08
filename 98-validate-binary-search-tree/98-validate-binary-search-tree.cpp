/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool f(TreeNode *root, long int left, long int right)
    {
        if(!root) return true;
        if(root->val <= left || root->val >= right) return false;
        return f(root->left, left, root->val) && f(root->right, root->val, right);
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return f(root, INT_MIN-1e4, INT_MAX+1e4);
    }
};