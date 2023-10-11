class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum  = 0;
        for(auto it : nums){
            if(sum < 0) sum = 0;
            sum += it;
            ans = max(sum,ans);
        }
        
        return ans;
    }
};