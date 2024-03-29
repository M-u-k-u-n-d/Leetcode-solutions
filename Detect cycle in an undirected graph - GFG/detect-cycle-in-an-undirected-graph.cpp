//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int src,int parent, int vis[], vector<int> adj[]){
                vis[src] = 1;
                // int size = adj[src].size();
                for(auto it : adj[src]){
                    if(!vis[it]) {
                        if(dfs(it,src,vis,adj)) return true;
                    }
                    else if(it != parent) return true;
                }
                return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
      int vis[V] = {0};
      
      for(int i=0; i<V; i++){
           if(vis[i] == 0){
               if(dfs(i,-1,vis,adj)) return true;
           }
      }
      return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends