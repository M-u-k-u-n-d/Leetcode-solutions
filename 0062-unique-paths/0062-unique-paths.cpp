class Solution {
// Tabulation
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int val1 =0, val2 =0;
                if(i==m-1 and j == n-1) continue;
                if(i != m-1) val1 = dp[i+1][j];
                if(j != n-1) val2 = dp[i][j+1];
                 dp[i][j] = val1+val2;
            }
        }
        return dp[0][0];
    }
};