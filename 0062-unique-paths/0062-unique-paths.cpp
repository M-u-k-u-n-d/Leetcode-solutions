class Solution {
// Tabulation
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int> (n,0));
        vector<int> dp(n,0);
        for(int i=m-1; i>=0; i--){
            vector<int> tmp(n);
            for(int j = n-1; j>=0; j--){
                int val1 =0, val2 =0;
                if(i==m-1 and j == n-1) {
                    tmp[j] = 1;
                    continue;
                }
                if(i != m-1) val1 = dp[j];
                if(j != n-1) val2 = tmp[j+1];
                 tmp[j] = val1+val2;
            }
            dp = tmp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};