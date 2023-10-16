class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        v.push_back({1});
        for(int i=1; i<=rowIndex; i++){
            vector<int> a;
            a.push_back(1);
            for(int j=1; j<i; j++){
                a.push_back(v[i-1][j]+v[i-1][j-1]);
            }
            a.push_back(1);
            v.push_back(a);
        }
        return v[rowIndex];
    }
};