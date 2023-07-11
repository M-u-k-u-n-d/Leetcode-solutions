class Solution {
   
public:
    int fib(int n) {
        if(n<=1) return n;
        int secprev = 0, prev = 1,ans;
        for(int i=2; i<= n; i++){
            ans = secprev + prev;
            secprev = prev;
            prev = ans;
        }
        return ans;
    }
};