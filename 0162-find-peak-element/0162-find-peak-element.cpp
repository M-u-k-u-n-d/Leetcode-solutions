class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() < 3){
            int ind = find(nums.begin(),nums.end(),*max_element(nums.begin(),nums.end())) - nums.begin();
            return ind;
        }
        
        int l=0, r = nums.size() -1; 
        int n = nums.size();
        while(l <= r){
            int mid = (l+r)/2;
            
            if(mid == 0){
                if(nums[mid] > nums[mid+1]) return mid;
                else l=mid+1;
            }  
            else if(mid == n-1){
                if(nums[mid] > nums[mid-1]) return mid;
                else r=mid-1;
            }
            else if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid+1]) l = mid+1;
            else r=mid-1;
        }
    return -1;
    }
};