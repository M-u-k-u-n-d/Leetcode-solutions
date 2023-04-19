class Solution {
    vector<int> nextsmaller(vector<int>a,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0; i--){
            int curr = a[i];
                while(s.top() != -1 and a[s.top()] >= curr) s.pop();
                ans[i] = s.top();
                s.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int>a,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n; i++){
            int curr = a[i];
                while(s.top() != -1 and a[s.top()] >= curr) s.pop();
                ans[i] = s.top();
                s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> next = nextsmaller(heights,n);
        vector <int> prev = prevsmaller(heights,n);
        
        int area = 0;
        for(int i=0; i<n; i++){
            if(next[i] == -1) next[i] = n;
            area = max(area,(next[i] - prev[i] -  1)*heights[i]);
        }
        return area;
    }
};