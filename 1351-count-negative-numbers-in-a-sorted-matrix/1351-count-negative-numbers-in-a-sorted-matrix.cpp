class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto it : grid){
            for(auto iit : it){
                if(iit < 0) ans++;
            }
        }
        return ans;
    }
};