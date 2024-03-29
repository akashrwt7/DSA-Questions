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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            long long sum = 0;
            for(int i=0; i<s; i++)
            {
                auto x = q.front();
                q.pop();
                sum += x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            double avg = (double)sum/s;
            ans.push_back(avg);
        }
        return ans;
        
        
    }
};