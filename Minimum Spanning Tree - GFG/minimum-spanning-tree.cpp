// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        dist[0] = 0;
        int ans = 0;
        for(int i=0; i<V; i++)
        {
            int u = -1;
            for(int j=0; j<V; j++)
            {
                if(!visited[j] && (u==-1 || dist[u]>dist[j]))
                {
                    u = j;
                }
            }
            visited[u] = true;
            ans += dist[u];
            for(auto v:adj[u])
            {
                if(!visited[v[0]])
                    dist[v[0]] = min(dist[v[0]], v[1]);
                // cout<<v[0];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends