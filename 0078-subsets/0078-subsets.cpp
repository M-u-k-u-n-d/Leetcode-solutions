class Solution {
    void f(vector<int> &a,vector<int>v,set<vector<int>> &ans,int ind){
        if(ind == a.size()){
            ans.insert(v);
            return;
        }
        for(int i=ind; i<a.size(); i++){
            v.push_back(a[i]);
            f(a,v,ans,i+1);
            v.pop_back();
            f(a,v,ans,i+1);
        }
        return;
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       set<vector<int>> ans;
        vector<int> v;
     f(nums,v,ans,0);
        vector<vector<int>>vpp;
        for(auto it : ans){
            vpp.push_back(it);
        }
        return vpp;
    }
};