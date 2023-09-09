class Solution {
    
    int f(int ind, int target, vector<int> nums,vector<int> &dp){
        if(target == 0) return 1;
        else if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += f(i,target-nums[i],nums,dp);
        }
        
        return dp[target] = sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        
        return f(0,target,nums,dp);
    }
};