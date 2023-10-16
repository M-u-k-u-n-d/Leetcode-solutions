class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        for(int i=1; i<=rowIndex; i++){
            vector<int> a;
            a.push_back(1);
            for(int j=1; j<i; j++){
                a.push_back(v[j]+v[j-1]);
            }
            a.push_back(1);
            if(i==rowIndex){
                return a;
            }
            v = a;
        }
        return v;
    }
};