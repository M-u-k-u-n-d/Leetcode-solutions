class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n = adjacentPairs.size();
        
        map<int,vector<int>> mpp;
        map<int,int> vis;
        vector<int> ans;
        
        
        for(int i=0; i<n; i++){
            mpp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mpp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        for(auto it : mpp){
            if(it.second.size() == 1){
                ans.push_back(it.first);
                vis[it.first] = true;
                break;
            }
        }
        
        for(int i=0; i<n; i++){  
            for(auto it : mpp[ans[i]]){
                // cout << it <<" ";
                if(!vis[it]){
                    ans.push_back(it);
                    vis[it] = true;
                }
            }
                // cout << endl;
        }
        
        return ans;
        
    }
};