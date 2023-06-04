class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
//         creating adjacency list
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                ans++;
                vis[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                   int size = adj[curr].size();
                    for(int j=0; j<size; j++){
                        if(vis[adj[curr][j]]==0){
                            vis[adj[curr][j]] = 1;
                            q.push(adj[curr][j]);
                        }
                    }
                        q.pop();
                }
            }
        }
        // for(auto it : adj){
        //     for(auto iit : it){
        //         cout << iit <<" ";
        //     }
        //     cout <<endl;
        // }
        return ans;
    }
};