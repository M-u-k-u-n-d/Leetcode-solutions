class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        double a = log(n)  / log(4);
        if(ceil(a) == floor(a)) return true;
        return false;
    }
};