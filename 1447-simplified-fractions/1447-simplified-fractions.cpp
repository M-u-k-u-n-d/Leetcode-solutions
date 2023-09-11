class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans; 
        map<double,int> mpp;
        for(int i=1; i<n; i++){
            
            for(int j=i+1; j<=n; j++){
                double num = (i*1.0/j);
                if(num < 1 and mpp[num] == 0){
                    mpp[num]++;
                    string s = "";
                    s += to_string(i);
                    s += '/';
                    s += to_string(j);
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};