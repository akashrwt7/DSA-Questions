class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), cmp);
        int n = pro.size();

        int ans = 0;
        int maxi = pro[0][0];
        for(int i=1; i<n; i++)
        {     
            if(maxi>pro[i][0])
                ans++;
            maxi = max(maxi, pro[i][0]);
        }
        
        
        return ans;
        
    }
};