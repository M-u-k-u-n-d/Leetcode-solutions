class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> ans;
        while(k--){
            if(nums.size() == 0){
                reverse(ans.begin(),ans.end());
                nums = ans;
                ans.clear();
                ans.push_back(nums.back());
                nums.pop_back();
            }
            else{
                ans.push_back(nums.back());
                nums.pop_back();
            }
        }
        
        reverse(ans.begin(),ans.end());
        for(auto it : nums){
            ans.push_back(it);
        }
        
        nums = ans;
    }
};