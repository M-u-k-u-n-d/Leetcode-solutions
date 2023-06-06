//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(int ind, vector<int> adj[], int color[]){
        color[ind] = 0;
        queue<int> q;
        q.push(ind);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int size = adj[curr].size();
            for(int i=0; i<size; i++){
                if(color[adj[curr][i]] == -1){
                    color[adj[curr][i]] =  !color[curr];
                    q.push(adj[curr][i]);
                }
                else if(color[adj[curr][i]] == color[curr]) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0; i<V; i++){
	        color[i] = -1;
	    }
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(!bfs(i,adj,color)) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends