class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int a[n][n];
        int  row = n, col = n, val = 1;
        int right = col-1, down = row-1, left = 0, up = 1, cnt=0,i=0,j=0;
        map<pair<int,int>,int>mpp;
        while(cnt < row*col){
            int tmp  = cnt;
            while(i<row and i>=0 and j<col and j>=0  and j<=right and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                a[i][j] = val;
                val++;
                cnt++;
                if(j==right) break;
                else
                j++;
               
            }
            right--;
            i++;
            while(j<col and j>=0 and i<row and i>=0  and i<=down  and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                a[i][j] = val;
                val++;
                cnt++;
                if(i==down) break;
                else
                i++;
            }
            j--;
            down--;
            while(i<row and i>= 0 and j<col and j>=0  and j>=left and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                // cout <<"check";
                a[i][j] = val;
                val++;
                cnt++;
                if(j==left) break;
                else
                j--;
                      }
               
            i--;
                left++;
            while(j<col and j>=0 and i<row and i>=0  and i>=up and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                     a[i][j] = val;
                     val++;
                     cnt++;
                     if(i==up) break;
                     else
                     i--;
                    }
                 
            j++;
            if(cnt == tmp) break;
            up++;
    }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int>v;
            for(int j=0; j<n; j++){
                v.push_back(a[i][j]);
            }
            ans.push_back(v);
        }
            return ans;
    }
};