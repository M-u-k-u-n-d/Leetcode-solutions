class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        vector<int> ans(nums.size(),-1);
       if(2*k+1 <= nums.size()){
        int tmp = k;
        long long sum = 0,j=0;
        while(tmp--){
            sum += nums[j];
            j++;
        }
        tmp = k+1;
        while(tmp--){
            sum += nums[j];
            j++;
        }
        int l=0;
        for(int i=k; i<nums.size()-k; i++){
            ans[i] = (sum/(2*k+1));
            sum -= nums[l];
            l++;
            if(j<nums.size())
            sum += nums[j];
            j++;
        }
       }
        
        return ans;
    }
};