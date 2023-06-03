//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans = 0;
        queue<int> q;
        vector<int> vis(V+1,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                ans++;
                vis[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                    int s = adj[curr].size();
                     vis[curr] = 1;
                    for(int j=0; j<s; j++){
                        if(adj[curr][j] != 0 and !vis[j]){
                            q.push(j);
                            vis[j] = 1;
                        }
                    }
                    q.pop();
                }
            }
        }
       
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends