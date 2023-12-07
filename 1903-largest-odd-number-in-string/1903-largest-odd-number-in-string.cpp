class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        // for( std:string::iterator it = num.rbegin(); it<num.rend(); it++){
        //     int n = it - '0';
        //     if(n%2){
        //         val = max(n,val);
        //     }
        // }
        
        int val = -1;
    for (std::string::reverse_iterator it = num.rbegin(); it != num.rend(); ++it) {
        int n = *it - '0'; // Dereference the iterator to get the character value
        if (n % 2) {
            string ans;
              for (auto itt = num.begin(); itt != it.base(); ++itt) {
                ans += *itt;
            }
            
            return ans;
        }
    }
        
        
        return ans;
    }
};