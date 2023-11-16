class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<int>> arr;
        
        for(auto it : wall){
            int sum = 0;
            vector<int> v;
            for(auto itt : it){
                sum += itt;
                v.push_back(sum);
            }
            
            arr.push_back(v);
        }
        
        map<int,int> mpp;
        for(auto it : arr){
            for(int i=0; i<it.size()-1; i++){
                mpp[it[i]]++;
            }
        }
        
        int mx = 0, n = wall.size();
        
        for(auto it : mpp){
            mx = max(mx,it.second);
        }
        
        return n-mx;
    }
};