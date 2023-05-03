class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for(int i=0; i<nums1.size(); i++)   s1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++)   s2.insert(nums2[i]);
        nums1.clear(),nums2.clear();
        for(auto it : s1) nums1.push_back(it);
        for(auto it : s2) nums2.push_back(it);
        vector<vector<int>> ans(2);
        for(int i=0; i<nums1.size(); i++){
            if(s2.find(nums1[i]) == s2.end()) ans[0].push_back(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            if(s1.find(nums2[i]) == s1.end()) ans[1].push_back(nums2[i]);
        }
        return ans;
    }
};