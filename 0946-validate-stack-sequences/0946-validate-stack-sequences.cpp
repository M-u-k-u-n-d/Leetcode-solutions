class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(),j=0;
        stack<int>st;
        vector<int>v = pushed;
        for(int i=0; i<n; i++){
            int tmp = popped[i];
            if(st.size()>0 and st.top() == tmp){
                st.pop();
                continue;
            }
            else{
                bool f=0;
                while(j<n){
                    if(v[j] == tmp){
                        f=1;
                        j++;
                        break;
                    }
                    else{
                        st.push(v[j]);
                    }
                    j++;
                }
                if(!f) return false;
            }
        }
        return true;
    }
};