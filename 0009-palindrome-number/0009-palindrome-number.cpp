class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        long long y=0,tmp = x;
        
        while(tmp > 0){
            y = y*10 + tmp%10;
            tmp /= 10;
        }
        
        return (x==y);
        
    }
};