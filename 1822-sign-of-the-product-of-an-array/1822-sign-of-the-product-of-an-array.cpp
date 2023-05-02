class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0, neg = 0, zero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] > 0 ) pos++;
            else neg++;
        }
        int ans;
        if(zero > 0) ans = 0;
        else if(neg%2 != 0) ans = -1;
        else ans = 1;
        return ans;
        
    }
};