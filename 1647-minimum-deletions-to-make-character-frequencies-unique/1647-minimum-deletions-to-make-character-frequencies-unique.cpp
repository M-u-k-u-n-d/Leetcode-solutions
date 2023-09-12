class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mpp;
        for(auto it : s){
            mpp[it]++;
        }
        
        vector<int> a;
        for(auto it : mpp){
            a.push_back(it.second);
        }
        
        sort(a.begin(),a.end(),greater<int>());
        vector<int> v(1e5,0);
        int cnt = 0;
        for(auto it : a){
            while(it > 0 and v[it] != 0){
                it--;
                cnt++;
            }
            v[it]++;
        }
        
        return cnt;
    }
};