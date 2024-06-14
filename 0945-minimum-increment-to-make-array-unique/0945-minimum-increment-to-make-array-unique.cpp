class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0, prev = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            while(nums[i] <= prev){
               cnt++;
                nums[i]++;
            }
            prev = nums[i];
            // cout << prev<<" ";
        }
        return cnt;
    }
};