class Solution {
    int f(vector<vector<int>> &dp, int row , int col , int m, int n ,vector<vector<int>> arr){
    if(row >= m || col >= n) return 0;
    if(arr[row][col] == 1) return 0;    
    if(row == m-1 and col == n-1) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    dp[row][col] = f(dp,row+1,col,m,n,arr) + f(dp,row,col+1,m,n,arr);
    return dp[row][col];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return f(dp,0,0,m,n,obstacleGrid);
    }
};