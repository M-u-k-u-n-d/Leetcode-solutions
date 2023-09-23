class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0){
                cnt++;
                i++;
                continue;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};