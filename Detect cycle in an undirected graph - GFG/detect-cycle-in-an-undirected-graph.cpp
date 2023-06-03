//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   bool check(int src, int vis[], vector<int> adj[]){
         queue<pair<int,int>> q;
         vis[src] = 1;
         q.push({src,-1});
         while(!q.empty()){
             int parent = q.front().second;
             int source = q.front().first;
             q.pop();
             int size = adj[source].size();
             for(auto num : adj[source]){
             if(vis[num] == 0){
                 vis[num] = 1;
                 q.push({num,source});
             }
             else if(num != parent) return true;
             }
         }
       return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
      int vis[V] = {0};
      
      for(int i=0; i<V; i++){
           if(vis[i] == 0){
               if(check(i,vis,adj)) return true;
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