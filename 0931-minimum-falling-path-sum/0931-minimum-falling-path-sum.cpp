class Solution {
 
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int row =n-2; row >= 0; row--){
            for(int col = 0; col < n; col++){
             int num1 = INT_MAX,num2 = INT_MAX,num3 = INT_MAX;
                if(col < n-1) num1 = dp[row+1][col+1];
                if(col > 0) num2 = dp[row+1][col-1];
                num3 = dp[row+1][col];
                dp[row][col] = matrix[row][col] + min(num1,min(num2,num3));
            }
        }
 
        return *min_element(dp[0].begin(),dp[0].end());
    }
};