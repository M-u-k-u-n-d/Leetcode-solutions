class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0,cnt=0;
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') st.push('(');
            else 
            {
                if(st.size() > 0 and st.top() == '(') st.pop();
                else ans++;
            }    
        }
        return ans+st.size();
    }
};