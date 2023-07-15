class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                        long long a = nums[i],b = nums[j],c=nums[k];
                                        long long sum = a+b+c, tg = target;
                                        long long num = tg-sum;
                                        int ind = lower_bound(nums.begin()+k+1,nums.end(),num) - nums.begin();
                                        if(ind < n and nums[ind] == num) {
                                        vector<int> v;
                                        v.push_back(nums[i]),v.push_back(nums[j]),v.push_back(nums[k]),v.push_back(num);
                                        sort(v.begin(),v.end());
                                        s.insert(v);
                                        }
                }
            }
        }
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};