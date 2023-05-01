class Solution {
public:
    double average(vector<int>& salary) {
        int mn = 10000000, mx = 0, sum = 0;
        int n = salary.size();
        for(int i=0; i<n; i++){
            mn = min(salary[i],mn);
            mx = max(salary[i],mx);
        }
        for(int i=0; i<n; i++){
            if(salary[i] == mn || salary[i] == mx) continue;
            sum += salary[i];
        }
        double ans = sum*1.0 / (n-2);
        return ans;
    }
};