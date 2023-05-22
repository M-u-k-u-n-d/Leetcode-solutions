class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto it : nums){
            ++mpp[it];
        }
        vector<int> ans;
        vector<pair<int,int>>vpp;
        for(auto it : mpp){
            vpp.push_back({it.second,it.first});
        }
        sort(vpp.begin(),vpp.end(),greater<>());
        for(int i=0; i<k; i++){
            ans.push_back(vpp[i].second);
        }
        return ans;
        
    }
};