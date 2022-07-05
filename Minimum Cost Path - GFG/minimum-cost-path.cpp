// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        while(!q.empty())
        {
            int d = q.top().first;
            auto p = q.top().second;
            q.pop();
            int i = p.first, j = p.second;
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(i==n-1 && j==m-1)
                break;
            if(i+1<n)
            {
                if(!visited[i+1][j])
                {
                    if(dist[i+1][j]>d+grid[i+1][j])
                    {
                        dist[i+1][j] = d + grid[i+1][j];
                        q.push({dist[i+1][j],{i+1,j}});
                    }
                }
            }
            
            
            if(j+1<m)
            {
                if(!visited[i][j+1])
                {
                    if(dist[i][j+1]>d+grid[i][j+1])
                    {
                        dist[i][j+1] = d + grid[i][j+1];
                        q.push({dist[i][j+1],{i,j+1}});
                    }
                }
            }
            
            if(i-1>=0)
            {
                if(!visited[i-1][j])
                {
                    if(dist[i-1][j]>d+grid[i-1][j])
                    {
                        dist[i-1][j] = d + grid[i-1][j];
                        q.push({dist[i-1][j],{i-1,j}});
                    }
                }
            }
            
            if(j-1>=0)
            {
                if(!visited[i][j-1])
                {
                    if(dist[i][j-1]>d+grid[i][j-1])
                    {
                        dist[i][j-1] = d + grid[i][j-1];
                        q.push({dist[i][j-1],{i,j-1}});
                    }
                }
            }
            


            
        }

        
        return dist[n-1][m-1];
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends