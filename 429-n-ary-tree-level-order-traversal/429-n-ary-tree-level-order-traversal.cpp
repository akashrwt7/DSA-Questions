/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        queue<Node *> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> lvl;
            for(int i=0; i<s; i++)
            {
                Node *temp = q.front();
                q.pop();
                lvl.push_back(temp->val);
                for(auto x:temp->children)
                {
                    q.push(x);
                }
            }
            ans.push_back(lvl);
        }
        return ans;
    }
       
};