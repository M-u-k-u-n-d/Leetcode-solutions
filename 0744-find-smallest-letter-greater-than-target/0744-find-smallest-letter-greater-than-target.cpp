class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        if(upper_bound(letters.begin(),letters.end(),target) != letters.end()){
            int ind = upper_bound(letters.begin(),letters.end(),target) - letters.begin();
            return letters[ind];
        }  
        return ans;
        
    }
};