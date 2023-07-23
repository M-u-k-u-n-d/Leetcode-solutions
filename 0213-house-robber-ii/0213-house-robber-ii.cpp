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
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        int lft =  f(nums,dp,1);
        vector<int> dpp(n+1,-1);
        nums.pop_back();
        int rgt = f(nums,dpp,0);
        // return rgt;
        return max(lft,rgt);
    }
};