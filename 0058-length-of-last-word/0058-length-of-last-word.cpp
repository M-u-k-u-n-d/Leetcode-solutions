class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        while(s.back() == ' ') s.pop_back();
        while(s.size() > 0 and s.back() != ' '){
            cnt++;
            s.pop_back();
        }
        return cnt;
    }
};