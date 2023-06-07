class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans  =0;
        int mx = max(a,max(b,c));
        
        while(mx>0){
            int cbit = c % 2;
            c /= 2;
            int one = 0;
            if(a&1) one++;
            if(b&1) one++;
            if(cbit == 1) {
                if(one == 0)
                ans++;
            }
            else ans  += one;
            a/=2,b/=2;
            mx/=2;
          }
        return ans;
    }
};