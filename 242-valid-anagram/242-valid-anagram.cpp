class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(n!=m) return 0;
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(int i=0; i<n; i++)
        {
            arr1[s[i]-'a']++;
            arr2[t[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }
};