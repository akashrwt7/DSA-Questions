class Solution {
public:
    
    
    int f(vector<int>& prices, int day, int k, int buy, vector<vector<vector<int>>> &dp)
    {
        if(k==0) return 0;
        if(day >= prices.size()) return 0;
        if(dp[day][k][buy]!=-1) return dp[day][k][buy];
        int profit = 0;
        if(buy)
        {
            int buy = profit - prices[day] + f(prices, day+1, k, 0, dp);
            int notBuy = f(prices, day+1, k, 1, dp);
            profit = max(buy, notBuy);
            // cout<<profit<<" "<<day<<" ";
        }
        else
        {
            // profit = profit + prices[day] + f(prices, day+1, k-1, 1);
            int sell = profit + prices[day] + f(prices, day+1, k-1, 1, dp);
            int notSell = f(prices, day+1, k, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[day][k][buy] = profit;
            
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1,vector<int>(2,-1)));
        int ans = f(prices, 0, k, 1, dp);
        return ans;
    }
};