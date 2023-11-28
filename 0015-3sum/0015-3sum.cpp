class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0; i<nums.size(); i++){
            int l = i+1, r= nums.size()-1;
            int x = -1 * nums[i];
            while(l<r){
                int nu = nums[l] + nums[r];
                if(x == nu){
                    vector<int> v = {nums[i] , nums[l] , nums[r]};
                    s.insert(v);
                    l++;
                }
                else if(x > nu) l++;
                else r--;
            }
        }
        
        for(auto it : s){
            vector<int> v;
        for(auto itt: it){
            v.push_back(itt);
        }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};