class Solution {
public:
    bool isPowerOfFour(int n) {
        int i=0;
        if(__builtin_popcount(n) != 1) return false;
        while(n>0){
            n /= 2;
            i++;
        }
        
        return i&1;
    }
};