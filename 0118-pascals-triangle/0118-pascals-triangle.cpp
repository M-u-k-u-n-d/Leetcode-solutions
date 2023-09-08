class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vpp;
        for(int i=1; i<= numRows; i++){
            vector<int> v;
            for(int j=0; j<i; j++){
                if(j == 0 || j == i-1){
                    v.push_back(1);
                }
                else{
                    cout << i <<" ";
                    int num = vpp[i-2][j] + vpp[i-2][j-1];
                    v.push_back(num);
                }
            }
            cout << endl;
            vpp.push_back(v);
        }
        
        return vpp;
    }
};