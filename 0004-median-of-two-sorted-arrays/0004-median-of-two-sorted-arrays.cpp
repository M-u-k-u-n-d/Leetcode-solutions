class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        
        int n = nums1.size(), m = nums2.size();
        int l=0,r=0;
        while(l < n or  r < m ){
            if(l == n){
                merge.push_back(nums2[r]);
                r++;
            }
            else if(r == m) {
                merge.push_back(nums1[l]);
                l++;
            }
            else{
                if(nums1[l] > nums2[r]){
                    merge.push_back(nums2[r]);
                    r++;
                }
                else{
                   merge.push_back(nums1[l]);
                    l++; 
                }
            }
        }
        
        int size = n + m;
        double ans;
        if(size%2 ){
             ans = merge[size/2];
        }
        else{
            ans = (merge[size/2-1] + merge[size/2])*1.0 / 2;
        }
        
        return ans;
    }
};