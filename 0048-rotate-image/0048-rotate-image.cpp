class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l=0,r=n-1;
        while(l<r){
            for(int i =0; i<n; i++){
                swap(matrix[i][l],matrix[i][r]);
            }
            l++;r--;
        }
        l=0,r=n-1;
        while(l<n and r >= 0){
            for(int i=0; i<n; i++){
                if(i+l == n-1) break;
                swap(matrix[i][l],matrix[r][n-1-i]);
            }
            
            l++;r--;
        }
    }
};