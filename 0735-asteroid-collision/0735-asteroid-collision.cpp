class Solution {
    void f(stack<int> &st, int num){
         if(!st.empty() and st.top() > 0 and  num < 0){
                    if(abs(st.top()) == abs(num)){
                        st.pop();
                    }
                    else if(abs(st.top()) > abs(num)){
                        return;
                    }
                    else{
                        st.pop();
                        f(st,num);
                        }
            }
            else{
                st.push(num);
            }
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            int num = asteroids[i];
            f(st,num);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};