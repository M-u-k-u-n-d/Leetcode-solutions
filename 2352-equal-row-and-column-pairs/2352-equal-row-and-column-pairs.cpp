class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> col;
        for(int i=0; i<grid.size(); i++){
            vector<int> v;
            for(int j=0; j<grid.size(); j++){
                v.push_back(grid[j][i]);
            }
            ++col[v];
        }
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            vector<int> v;
            for(int j=0; j<grid.size(); j++){
                v.push_back(grid[i][j]);
            }
            ans += col[v];
        }
        return ans;
    }
};