class Solution {
public:
    bool isValid(string s) {
        int n = s.length(),a=0,b=0,c=0;
        stack <char> st;
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
            if(st.size() == 0) return false;
                 char ch = st.top();
            if(s[i] == ')'){
                if(ch != '(') return false;
            }
            if(s[i] == '}' and ch != '{'){
                return false;
            } 
            if(s[i] == ']' and ch != '['){
                return false;
            }
                st.pop();
            }
        }
        if(st.size() == 0)
        return true;
        return false;
    }
};