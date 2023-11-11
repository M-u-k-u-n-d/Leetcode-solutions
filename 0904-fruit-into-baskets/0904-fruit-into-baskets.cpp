class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int l=0,n= fruits.size();
        int ans = INT_MIN;
        set<int> st;
        map<int,int> mpp;
        for(int i=0; i<fruits.size(); i++){
            mpp[fruits[i]]++;
            st.insert(fruits[i]);
            while(st.size() > 2) {
                // cout << i <<" "<<l<<endl;
                ans = max(ans, i-l);
                if(mpp[fruits[l]] == 1){
                st.erase(fruits[l]);
                }
                mpp[fruits[l]]--;
                l++;
            }
        }
        
        ans = max(ans,n-1-l+1);
        
        return ans;
    }
};