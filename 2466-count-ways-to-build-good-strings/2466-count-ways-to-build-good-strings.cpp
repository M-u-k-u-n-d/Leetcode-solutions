
const int mod=1e9+7;
class Solution {
public:
    long fun(int n,int zero,int one,int low,int high,vector<long>& dp)
    {
        if(n>high) return 0;
        if(dp[n]!=-1) return dp[n];
        long ans=(fun(n+zero,zero,one,low,high,dp)%mod+fun(n+one,zero,one,low,high,dp)%mod)%mod;
        if(n>=low&&n<=high)
        {
            ans=(ans+1)%mod;
        }
        return dp[n]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> dp(high+1,-1);
        return (int)fun(0,zero,one,low,high,dp);
    }
};