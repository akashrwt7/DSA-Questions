// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int> mp;
        for(int i=0; i<2*N; i=i+2)
        {
            mp[arr[i]] = arr[i+1];
        }
        queue<int> q;
        q.push(1);
        vector<int> visited(31, false);
        visited[1] = 1;
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            int s = q.size();
            for(int x = 0; x<s; x++)
            {
                int u = q.front();
                q.pop();
                for(int i=1; i<=6; i++)
                {
                    int v = u+i;
                    if(v==30) return ans;
                    if(!visited[v])
                    {
                        if(mp.find(v)!=mp.end())
                        {
                            q.push(mp[v]);
                            visited[v] = 1;
                            visited[mp[v]] = 1;
                        }
                        else
                        {
                            q.push(v);
                            visited[v] = 1;
                        }
                    }
                }
            }
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends