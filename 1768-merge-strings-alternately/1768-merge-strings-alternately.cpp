class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size() + word2.size(),i=0,j=0;
        bool f = 0;
        while(n--){
            if(!f and i < word1.size()){
                ans += word1[i];
                i++;
                f=1;
                if(j == word2.size()) f = 0;
            }
            else{
                ans += word2[j];
                j++;
                f=0;
                if(i==word1.size()) f=1;
            }
        }
        return ans;
    }
};