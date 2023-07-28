class Solution {
//     int f(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
//         if(i==0 and j == 0) return grid[0][0];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int val1 = INT_MAX, val2 =INT_MAX;
        
//         if(i>0) val1 = grid[i][j] + f(i-1,j,m,n,dp,grid);
//         if(j>0) val2 = grid[i][j] + f(i,j-1,m,n,dp,grid);
        
//         return dp[i][j] = min(val1,val2);
//     }
        
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        // vector<vector<int>> dp (m,vector<int> (n,-1));
        vector<int> dp(n);
        for(int i=0; i<m; i++){
            vector<int> tmp(n);
            for(int j=0; j<n; j++){
                if(i==0 and j==0)  tmp[0] = grid[0][0];
                else{
                    int val1 = INT_MAX, val2 =INT_MAX;
        
                    if(i>0) val1 = grid[i][j] +  dp[j];
                    if(j>0) val2 = grid[i][j] +  tmp[j-1];
        
                    tmp[j] = min(val1,val2);
                }
            }
            dp = tmp;
        }
            
        
        return dp[n-1];
    }
};