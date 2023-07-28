class Solution {
    int f(int row,int col, vector<vector<int>>& arr, int n,vector<vector<int>>& dp){
        if(row == n-1) return arr[row][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];
        int num1 = INT_MAX,num2 = INT_MAX,num3 = INT_MAX;
        if(col < n-1) num1 = f(row+1,col+1,arr,n,dp);
        if(col > 0) num2 = f(row+1,col-1,arr,n,dp);
        num3 = f(row+1,col,arr,n,dp);
        
        return dp[row][col] = arr[row][col] + min(num1,min(num2,num3));
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0; i<n; i++)
        ans = min(ans, f(0,i,matrix,matrix.size(),dp));
        return ans;
    }
};