class Solution {
public:
    int pivotInteger(int n) {
        vector<int> presum(n+1);
        presum[0] = 0;
        for(int i=1; i<=n; i++){
            presum[i] += presum[i-1] + i;
        }
        int sum = 0;
        for(int i=n; i>=1; i--){
            sum += i;
            if(sum == presum[i]) return i;
        }
        return -1;
    }
};