// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isSafe(int i, int j, int n, int m, vector<vector<int>> &A)
  {
      if(i>=0 && i<n && j>=0 && j<m && A[i][j]==1) return true;
      else return false;
  }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0]=0;
        int ans = 0;
        while(!q.empty())
        {
            int s = q.size();
            ans++;
            for(int i=0; i<s; i++)
            {
                auto p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if(x==X && y==Y) return ans-1;
                if(isSafe(x+1,y,N,M,A))
                {
                    A[x+1][y] = 0;
                    q.push({x+1,y});
                }
                
                if(isSafe(x-1,y,N,M,A))
                {
                    A[x-1][y] = 0;
                    q.push({x-1,y});
                }
                    
                if(isSafe(x,y+1,N,M,A))
                {
                    A[x][y+1] = 0;
                    q.push({x,y+1});
                }
                    
                if(isSafe(x,y-1,N,M,A))
                {
                    A[x][y-1] = 0;
                    q.push({x,y-1});
                }
                    
                
            }
            
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends