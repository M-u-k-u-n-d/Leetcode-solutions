class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int last = k-1;
        
        int sum = 0;
        for(int i =last; i>= 0; i--){
            sum += cardPoints[i];
        }
        int ans = sum;
        for(int i=n-1; i >= n-k; i--){
            sum -= cardPoints[last];
            last--;
            sum += cardPoints[i];
            ans = max(sum,ans);
        }
        
        return ans;
    }
};