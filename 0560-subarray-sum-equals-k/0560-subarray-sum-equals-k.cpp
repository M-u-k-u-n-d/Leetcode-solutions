class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        vector<int> preSum(nums.size());
        preSum[0] = nums[0];
      for(int i=1; i<nums.size(); i++){
          preSum[i] = preSum[i-1]+ nums[i];
      }
        // reverse(preSum.begin(),preSum.end());
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
          if(preSum[i] == k) cnt++;
          if(mpp[preSum[i] - k] > 0){
              cnt+=mpp[preSum[i] - k];
          }
            
            mpp[preSum[i]]++;
        }
        
        return cnt;
    }
};