class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l+r) / 2;
            if(nums[mid] == target) return true;
            
            if(nums[mid] == nums[l] and nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }
            
            if(nums[mid] >= nums[l]){
                if(nums[l] <= target and target < nums[mid]){
                    r = mid-1;
                }
                else    l = mid+1;
            }
            else{
                if(nums[r] >= target and nums[mid] < target) l = mid+1;
                else r = mid-1;
            }
                      }
        
        return false;
    }
};