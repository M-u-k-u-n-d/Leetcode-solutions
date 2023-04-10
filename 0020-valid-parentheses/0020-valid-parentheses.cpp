class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
//              IF STACK IS EMPTY AND s[i] IS A CLOSING BRACKET   
            if(st.size() == 0) return false;
                 char ch = st.top(); // top element of stack 
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