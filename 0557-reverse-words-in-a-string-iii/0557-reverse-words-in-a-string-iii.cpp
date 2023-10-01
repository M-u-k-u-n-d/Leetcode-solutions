class Solution {
public:
    string reverseWords(string s) {
        string ans,temp;
        for(auto it : s){
            if(it == ' '){
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += " ";
                temp = "";
            }
            else{
                temp += it;
            }
        }
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};