class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        
        int ans = 0;
        
        for(auto it : mpp){
            ans += (it.second * (it.second-1) / 2);
        }
        
        return ans;
    }
};