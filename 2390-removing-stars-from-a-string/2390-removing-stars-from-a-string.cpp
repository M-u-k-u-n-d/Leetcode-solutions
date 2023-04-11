class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                if(st.size() > 0) st.pop(); // removing element from stack
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(st.size()>0){
            ans += st.top(); // last element which is inserted in stack
            st.pop();   // removing element from stack
        }
        reverse(ans.begin(),ans.end()); // reverse the string
        return ans;
    }
};