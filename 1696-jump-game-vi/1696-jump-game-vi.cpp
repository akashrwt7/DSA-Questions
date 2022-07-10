class Solution {
public:
    // int f(vector<int>& nums, int k, int i)
    // {
    //     if(i>=n) return -1e9;
    //     if(i==n-1) return nums[n-1];
    //     int ans = 
    // }
    
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        for(int i=1; i<min(1+k,n); i++)
        {
            int maxi = *rbegin(s);
            // cout<<maxi<<" ";
            dp[i] = nums[i] + maxi;
            s.insert(dp[i]);
        }
        for(int i=k+1; i<n; i++)
        {
            s.erase(s.find(dp[i-k-1]));
            int maxi = *rbegin(s);
            // cout<<maxi<<" ";
            dp[i] = nums[i] + maxi;
            s.insert(dp[i]);
        }
        // for(int i=0; i<n; i++)
        //     cout<<dp[i]<<" ";
        return dp[n-1];
    }
};