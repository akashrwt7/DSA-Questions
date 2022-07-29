class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
        vector<string> ans;
        unordered_map<char,vector<int>> pm;
        for(int i=0; i<pattern.length(); i++)
        {
            pm[pattern[i]].push_back(i);
        }
        
        for(auto s:words)
        {
            if(s.length()!=pattern.length()) continue;
            unordered_map<char,vector<int>> mp;
            for(int i=0; i<s.length(); i++)
            {
                mp[s[i]].push_back(i);
            }
            bool flag = 1;
            // unordered_set<char> S;
            if(pm.size() != mp.size()) continue;
            for(int i=0; i<s.length(); i++)
            {
                if(mp[s[i]] != pm[pattern[i]])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(s);
            
        }
        
        return ans;
    }
};