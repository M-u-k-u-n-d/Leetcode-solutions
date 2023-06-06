class Solution {
    void dfs(int val,vector<int> &vis,vector<vector<int>> adj,stack<int> &st){
        vis[val] = 1;
        for(auto it : adj[val]){
            if(!vis[it])    {
                 dfs(it,vis,adj,st);
            }
        }
         st.push(val);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
           for(auto it : adj[i]){
               indegree[it]++;
           }
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> vec;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
            vec.push_back(curr);
        }
        
        if(vec.size() != numCourses) return {};
        vector<int> vis(numCourses,0);
        stack<int> st;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector <int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};