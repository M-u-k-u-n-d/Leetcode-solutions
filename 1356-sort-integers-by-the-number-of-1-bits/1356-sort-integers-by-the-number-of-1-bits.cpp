class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vpp;
        vector<int> ans;
        
        for(auto it : arr){
            vpp.push_back({__builtin_popcount(it),it});
        }
                          
        sort(vpp.begin(),vpp.end());
                          
        for(auto it : vpp){
            ans.push_back(it.second);
        }
                          
        return ans;
    }
};