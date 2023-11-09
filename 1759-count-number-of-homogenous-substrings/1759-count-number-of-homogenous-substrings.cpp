class Solution {
    int mod = 1000000007;
public:
    long long countHomogenous(string s) {
        long long cnt = 1,ans = 0;
       for(int i=1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                ans += (cnt%mod * (cnt+1)%mod) %mod / 2;
                cnt = 1;
            }
           else{
               cnt++;
           }
           
       }
        
       ans += (cnt%mod * (cnt+1)%mod) %mod / 2;
       return ans;
    }
};