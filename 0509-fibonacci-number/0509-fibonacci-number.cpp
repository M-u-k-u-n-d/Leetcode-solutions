class Solution {
    int f(int n, int dp[]){
        if(n <= 1) return n;
        if(dp[n] == -1){
        dp[n] = f(n-1,dp)+f(n-2,dp);
            return dp[n];
        }
        return dp[n];
    }
public:
    int fib(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        return f(n,dp);
    }
};