class Solution {
int f(vector<vector<int>> &dp, int row , int col , int m, int n ){
    if(row >= m || col >= n) return 0;
    if(row == m-1 and col == n-1) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    dp[row][col] = f(dp,row+1,col,m,n) + f(dp,row,col+1,m,n);
    return dp[row][col];
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return f(dp,0,0,m,n);
    }
};