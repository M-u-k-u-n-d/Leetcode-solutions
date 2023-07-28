class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2; i>= 0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                    int val1 =  triangle[i][j]+ dp[i+1][j];
                    int val2 =  triangle[i][j] + dp[i+1][j+1];
                 dp[i][j] = min(val1,val2);
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};