class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            int low = i, high = i;
            
            for(int j=i; j<= high; j++){
                for(int k = s.size()-1; k>=0; k--){
                    if(s[j] == s[k]){
                        high = max(high, k);
                        break;
                    }
                }
            }
            
            i=high;
            ans.push_back(high-low+1);
        }
        
        return ans;
    }
};