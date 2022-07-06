// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>adj){
	    // Code here
	    vector<int> dist(V,1e8);
	    int S =0;
        dist[S] = 0;
        for(int i=0; i<(V-1); i++)
        {
            for(auto u:adj)
            {
                if(dist[u[1]]>dist[u[0]]+u[2])
                    dist[u[1]] = dist[u[0]]+u[2];
            }
        }
        for(auto u:adj)
        {
            if(dist[u[1]]>dist[u[0]]+u[2])
                return 1;
        }
        return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends