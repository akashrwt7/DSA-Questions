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
    
    int f(TreeNode *root)
    {
        if(!root) return 0;
        int left = f(root->left);
        int right = f(root->right);
        int sum = root->val + left + right;
        if(left == 0) root->left = nullptr;
        if(right == 0) root->right = nullptr;
        return sum;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        // if(!root->left && !root->right && root->val ==0) return nullptr;
        int sum = f(root);
        if(sum==0) return nullptr;
        return root;
    }
};