class Solution {
    int binary_search(vector<int> arr, int lft, int rgt){
        int mid = (lft + rgt) /2;
        while(lft < rgt){
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] > arr[mid-1]) lft = mid+1;
            else rgt = mid;
            
            mid = (lft+rgt)/2;
        } 
        return lft;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return binary_search(arr,0,arr.size()-1);
    }
};