class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>= 0; i--){
            vector<int> tmp(triangle[i].size());
            for(int j=0; j<triangle[i].size(); j++){
                    int val1 =  triangle[i][j]+ dp[j];
                    int val2 =  triangle[i][j] + dp[j+1];
                 tmp[j] = min(val1,val2);
            }
            dp = tmp;
        }
        for(auto it : dp) cout << it <<" ";
        return *min_element(dp.begin(),dp.end());
    }
};