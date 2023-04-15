class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // if(s1 == s2) return 0;
        int x=0 , y=0;
        for(int i=0; i<s1.length(); i++){
           if(s1[i] != s2[i]) {
                if(s1[i] == 'x') x++;
               else y++;
           }
        }
        if((x+y)%2 != 0) return -1;
        int ans = ceil (x*1.0/2) + ceil(y*1.0/2);
        return ans;
    }
};