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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                auto x = q.front();
                q.pop();
                int maxi = x.second, data = x.first->val;
                if(data>=maxi) ans++;
                maxi = max(maxi, data);
                if(x.first->left)
                    q.push({x.first->left, maxi});
                if(x.first->right)
                    q.push({x.first->right, maxi});                
            }
        }
        return ans;
        
        
        
    }
};