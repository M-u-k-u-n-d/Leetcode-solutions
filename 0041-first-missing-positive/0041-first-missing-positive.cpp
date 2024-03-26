class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        
        for(int i=1; i<=100002; i++){
            if(mpp[i] == 0) return i;
        }
        
        return -1;
    }
};