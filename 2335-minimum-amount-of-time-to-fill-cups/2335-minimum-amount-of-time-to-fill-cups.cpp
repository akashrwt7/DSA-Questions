class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int n  = amount.size();
        for(int i=0; i<n; i++)
        {
            if(amount[i]>0)
                pq.push(amount[i]);
        }
        int ans = 0;
        while(pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x--; y--;
            ans++;
            if(x>0) pq.push(x);
            if(y>0) pq.push(y);
        }
        if(pq.empty()) return ans;
        ans += pq.top();
        return ans;
        
    }
};