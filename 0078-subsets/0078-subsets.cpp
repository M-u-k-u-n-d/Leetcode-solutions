class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       // set<vector<int>> ans;
        vector<vector<int>>vpp;
        int n = pow(2,nums.size());
        
       for(int i=0; i<n; i++){
           vector<int> v;
           for(int j=0; j<nums.size(); j++){
               if(i & (1<<j)) v.push_back(nums[j]);
           }
           vpp.push_back(v);
       }
           
        return vpp;
    }
};