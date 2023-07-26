class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        dp[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i==m-1 and j==n-1) continue;
                long long val1 = 0, val2 = 0;
                 if(i != m-1) val1 = dp[i+1][j];
                if(j != n-1) val2 = dp[i][j+1];
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else
                    dp[i][j] = val1 + val2;
            }
        }
        return dp[0][0];
    }
};