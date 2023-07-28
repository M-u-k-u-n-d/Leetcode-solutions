class Solution {
    
    int f(vector<vector<int>>& arr,int row , int col,vector<vector<int>>& dp) {
        if(row == arr.size()-1) return arr[row][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];
        int val1 = arr[row][col]+f(arr,row+1,col,dp);
        int val2 = arr[row][col] + f(arr,row+1,col+1,dp);
        return dp[row][col] = min(val1,val2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size() , vector<int> (250, INT_MAX));
        return f(triangle, 0,0,dp);
    }
};