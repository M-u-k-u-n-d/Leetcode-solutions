class Solution {
  int  f(int l, int r, vector<int>a,int target){
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid] == target) return mid;
            else if(a[mid] > target){
                if(a[mid] >= a[l] and a[mid] > a[r]) {
                    if(a[l] <= target ) r = mid;
                    else  l= mid+1;
                }  
                else r=mid;
            }
            else{
               if(a[mid] < a[l] and a[mid] < a[r]) {
                   if(a[l] > target) l = mid+1;
                   else  r = mid;
               }
               else   l = mid+1;
            }
            }
        if(a[l] == target) return l;
        return -1;
        }
public:
    int search(vector<int>& nums, int target) {
        // if(nums.size() == 1) {
        //     if(nums[0] == target) return 0;
        //     return -1;
        // }
        return f(0,nums.size()-1,nums,target);        
    }
};