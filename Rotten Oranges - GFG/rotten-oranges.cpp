// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int dir[][2] = {-1,0,1,0,0,-1,0,1};
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        int ans = -1;
        while(!q.empty())
        {
            
            int s = q.size();
            ans++;
            for(int i=0; i<s; i++)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                
                for(int i=0; i<4; i++)
                {
                    int t1 = x+dir[i][0];
                    int t2 = y+dir[i][1];
                    if(t1>=0 && t1<n && t2>=0 && t2<m)
                    {
                        if(grid[t1][t2]==1)
                        {
                            grid[t1][t2] = 2;
                            q.push({t1,t2});
                        }
                    }
                    else
                        continue;
                }
                
                // if(x+1<n)
                // {
                //     if(grid[x+1][y]==1)
                //     {
                //         grid[x+1][y] = 2;
                //         q.push({x+1, y});
                //     }
                // }
                // if(y+1<m)
                // {
                //     if(grid[x][y+1]==1)
                //     {
                //         grid[x][y+1] = 2;
                //         q.push({x, y+1});
                //     }
                // }
                // if(x-1>=0)
                // {
                //     if(grid[x-1][y]==1)
                //     {
                //         grid[x-1][y] = 2;
                //         q.push({x-1, y});
                //     }
                // }
                // if(y-1>=0)
                // {
                //     if(grid[x][y-1]==1)
                //     {
                //         grid[x][y-1] = 2;
                //         q.push({x, y-1});
                //     }
                // }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends