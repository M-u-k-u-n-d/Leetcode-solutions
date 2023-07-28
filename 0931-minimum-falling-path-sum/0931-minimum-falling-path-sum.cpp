class Solution {
 
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = matrix[n-1][i];
        }
        for(int row =n-2; row >= 0; row--){
            vector<int> tmp(n);
            for(int col = 0; col < n; col++){
             int num1 = INT_MAX,num2 = INT_MAX,num3 = INT_MAX;
                if(col < n-1) num1 = dp[col+1];
                if(col > 0) num2 = dp[col-1];
                num3 = dp[col];
                tmp[col] = matrix[row][col] + min(num1,min(num2,num3));
            }
            dp = tmp;
        }
 
        return *min_element(dp.begin(),dp.end());
    }
};