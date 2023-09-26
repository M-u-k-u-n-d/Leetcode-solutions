class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mpp;
        for(auto it : s){
            mpp[it]++;
        }
        
        stack<char> st;
        map<char,int> vis;
        for(auto it : s){
            if(vis[it] > 0) {
                mpp[it]--;
                continue;
            }
            if(st.empty()){
                st.push(it);
                mpp[it]--;
                vis[it]++;
            }
            else{
                char val = st.top();
                
                if(val > it and mpp[val] > 0){
                    while(st.size() > 0 and st.top() > it and mpp[st.top()] > 0){
                         vis[st.top()] = 0;
                         st.pop();
                    }
                    st.push(it);
                    vis[it]++;
                    mpp[it]--;
                }
                else{
                    st.push(it);
                    vis[it]++;
                    mpp[it]--;
                }
            }
        }
        
        
    string ans;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
            
    
    }
};