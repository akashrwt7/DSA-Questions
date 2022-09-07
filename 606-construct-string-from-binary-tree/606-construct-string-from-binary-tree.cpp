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
    void preorder(TreeNode *root, string &ans)
    {
        ans += "(";
        if(root){
            ans += to_string(root->val);
            if(root->left || (!root->left && root->right))
                preorder(root->left, ans);
            if(root->right)
            preorder(root->right, ans);
        }
        ans += ")";
    }
    
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans = to_string(root->val);
        if(root->left || (!root->left && root->right))
            preorder(root->left, ans);
        if(root->right)
            preorder(root->right, ans);        
        return ans;
    }
};