// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    // int mat[8] = {1,0,-1,0,0,1,0,-1};
    
    bool DFS(vector<vector<int>>& grid, int i, int j, int n)
    {
        if(i<0 || i>=n || j<0 || j>=n)
            return false;
        if(grid[i][j]==2) return true;
        if(grid[i][j]==0) return false;
        grid[i][j] = 0;
        return DFS(grid,i+1,j,n) || DFS(grid,i-1,j,n) || DFS(grid,i,j-1,n) || DFS(grid,i,j+1,n);

        
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int i,j;
        for( i=0; i<n; i++)
        {
            for( j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                return DFS(grid,i,j,n);
            }
        }
        return false;
        
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends