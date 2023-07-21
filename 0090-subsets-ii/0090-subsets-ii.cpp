class Solution {
    void f(vector<int> nums,set<vector<int>> &st,int ind, vector<int> &v){
        if(ind == nums.size()){
            st.insert(v);
            return;
        }
        for(int i=ind;i<nums.size(); i++){
            v.push_back(nums[i]);
            f(nums,st,i+1,v);
            v.pop_back();
            f(nums,st,i+1,v);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> v;
        f(nums,st,0,v);
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};