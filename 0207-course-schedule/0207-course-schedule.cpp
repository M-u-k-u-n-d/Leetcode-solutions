class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
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
        
        if(vec.size() == numCourses) return true;
        return false;
    }
};