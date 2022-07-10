class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length(), m = target.length();
        if(n!=m) return false;
        unordered_map<char,int> smp, tmp;
        for(int i=0; i<n; i++)
        {
            if(start[i]!='_')
                smp[start[i]]++;
            if(target[i]!='_')
                tmp[target[i]]++;
        }

        if(smp['L'] != tmp['L'] || smp['R']!=tmp['R'])
            return false;
        int left=-1, right = -1;
        for(int i=0; i<n; i++)
        {
            char ch = target[i];
            if(ch=='_')
                continue;
            if(ch=='L')
            {
                // cout<<ch<<" ";
                int j;
                if(left==-1)
                    j=i;
                else
                    j=max(left,i);
                bool flag = false;
                for( ; j<n; j++)
                {
                    if(start[j]== ch)
                    {
                        // cout<<ch<<" ";
                        flag = true;
                        left = j;
                        start[j] = 'l';
                        break;
                    }
                    else if(start[j]=='R' || start[j]=='r')
                    {
                        // cout<<ch<<" ";
                        return false;
                    }
                }
                if(!flag)
                {
                    // cout<<ch<<" ";
                    return false;
                }
            }
            else if(ch=='R')
            {
                // cout<<ch<<" ";
                int j;
                if(right==-1)
                    j=i;
                else
                    j=max(right,i);
                bool flag = false;
                for(; j>=0; j--)
                {
                    if(start[j]== ch)
                    {
                        // cout<<ch<<" ";
                        flag = true;
                        right = j;
                        start[j] = 'r';
                        break;
                    }
                    else if(start[j]=='L' || start[j]=='l')
                    {
                        // cout<<ch<<" ";
                        return false;
                    }
                }
                if(!flag) return false;
            }
        }
        return true;
        
    }
};