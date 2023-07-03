class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() == 1 || s.length() != goal.length()) return false;
        else if(s == goal){
            set<char> st;
            for(auto it : s){
                st.insert(it);
            }
            if(st.size() != s.length()) return true;
            return false;
        }
        int l = 0, r = s.length()-1;
        while(l<r){
            if(s[l] != goal[l] and s[r] != goal[r]){
                swap(s[l],s[r]);
                break;
            }
            if(s[l] == goal[l]) l++;
            if(s[r] == goal[r]) r--;
        }
        if(s == goal) return true;
        return false;
    }
};