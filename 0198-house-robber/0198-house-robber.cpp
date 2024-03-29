class Solution {
    

    int f(vector<int> nums,vector<int> &dp, int ind){
       if(ind == nums.size()-1) return nums[ind];
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + f(nums,dp,ind+2);
        int notpick = f(nums,dp,ind+1);
        
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(nums,dp,0);
    }
};