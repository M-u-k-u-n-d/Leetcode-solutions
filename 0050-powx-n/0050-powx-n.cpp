class Solution {
    double power(double x, long long  n, double mul){
        if(n <= 0){
            return mul;
        }
        if(n%2 == 0){
            x *= x;
            n /= 2;
        }
        else {
            mul *= x;
            n--;
        }
        return power(x,n,mul);
    }
public:
    double myPow(double x, int n) {
       double mul = 1;
        long long num = abs(n);
      double  result = power(x,num,mul);
        // cout << result;
        if(n < 0){
            result = 1 / result;
        }
        return result;
    }
};