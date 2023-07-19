class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string st = "";
        for(int i=0; i<s.length(); i++){
            if(i == s.length()-1){
                if(s[i] != ' '){
                    st += s[i];
                    v.push_back(st);
                }
                else if(st != ""){
                v.push_back(st);
                }
            }
            else if(s[i] == ' ' and st != ""){
                v.push_back(st);
                st = "";
            }
            else if(s[i] != ' '){
                st += s[i];
            }
            
        }
        string ans;
        reverse(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            if(i==v.size()-1){
                ans += v[i];
            }
            else{
                ans += v[i];
                ans += " ";
            }
        }
        return ans;
    }
};