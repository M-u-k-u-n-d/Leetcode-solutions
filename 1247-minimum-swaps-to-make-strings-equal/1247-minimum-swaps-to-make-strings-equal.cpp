class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x=0 , y=0;
        for(int i=0; i<s1.length(); i++){
           if(s1[i] != s2[i]) {
                if(s1[i] == 'x') x++;
               else y++;
           }
        }
        if((x+y)%2 != 0) return -1;
        int ans = (x+1)/2 + (y+1)/2;
        return ans;
    }
};