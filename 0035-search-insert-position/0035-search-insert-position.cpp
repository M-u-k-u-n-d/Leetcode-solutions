class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        // if(target < nums[0]) return 0;
        int mid = (l+r)/2;
        while(l<r){
            if(nums[mid] == target) return mid;  
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
            mid = (l+r)/2;
        }
        if(nums[l] >= target) return l;
        return l+1;
    }
};