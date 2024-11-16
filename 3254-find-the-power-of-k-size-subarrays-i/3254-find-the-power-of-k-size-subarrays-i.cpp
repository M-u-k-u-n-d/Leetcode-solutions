class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,-1);
        
        for(int i=0; i<=n-k; i++){
            int val = nums[i];
            for(int j=i+1; j<i+k; j++){
                if(val+1 == nums[j]){
                    val = nums[j];
                }
                else{
                    val = -1;
                    break;
                }
            }
            ans[i] = val;
        }
        return ans;
    }
};