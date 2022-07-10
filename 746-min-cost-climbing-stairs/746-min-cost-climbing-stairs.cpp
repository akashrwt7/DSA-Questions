class Solution {
public:
    
    
    // int f(vector<int>& cost, int i, int n, vector<int> &dp)
    // {
    //     if(i>=n) return 0;
    //     // if(i>n) return 1e9;
    //     if(dp[i]!=-1) return dp[i];
    //     int one = cost[i] + f(cost, i+1, n, dp);
    //     int two = cost[i] + f(cost, i+2, n, dp);
    //     return dp[i] = min(one,two);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        // int zero = f(cost, 0, n, dp);
        // int one = f(cost, 1, n, dp);
        for(int i=n-1; i>=0; i--)
        {
            int one = cost[i], two = cost[i];
            if(i+1<n)  one = cost[i] + dp[i+1];
            if(i+2<n)  two = cost[i] + dp[i+2];
            dp[i] = min(one,two);
        }
        return min(dp[0], dp[1]);
    }
};