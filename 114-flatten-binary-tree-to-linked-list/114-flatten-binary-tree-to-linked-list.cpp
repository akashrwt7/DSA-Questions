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
    
    
    
    TreeNode* prev = NULL;
    void pre(TreeNode* curr)
    {
        if(!curr) return;
        if(prev)
            prev->right = curr;
        prev = curr;
        TreeNode *next = curr->right;
        flatten(curr->left);
        curr->left = NULL;
        flatten(next);

        
    }
    
    void flatten(TreeNode* root) {
        pre(root);
    }
};