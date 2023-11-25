class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
            
        int n = nums.size();
        vector<int> leftPrifixSum(n), rightPrifixSum(n);

        vector<int> ans;
        leftPrifixSum[0] = nums[0];
        rightPrifixSum[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            leftPrifixSum[i] = leftPrifixSum[i-1] + nums[i];
        }
        
        for(int i=n-2;i >=0; i--){
             rightPrifixSum[i] = rightPrifixSum[i+1] + nums[i];
        }
        
        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back(abs(rightPrifixSum[i+1] - (n-i-1)* nums[i]));
            }
            else if(i==n-1){
                ans.push_back(abs(leftPrifixSum[i-1] - i * nums[i]));
            }
            else{
                ans.push_back(abs(rightPrifixSum[i+1] - (n-i-1)* nums[i]) + abs(leftPrifixSum[i-1] - i * nums[i]));
            }
        }
        
        // for(auto it  : leftPrifixSum) cout << it <<" ";
        
        // cout << endl;
        return ans;
    }
};