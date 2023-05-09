class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int  row = matrix.size(), col = matrix[0].size();
        int right = col-1, down = row-1, left = 0, up = 1, cnt=0,i=0,j=0;
        map<pair<int,int>,int>mpp;
        while(cnt < row*col){
            int tmp  = cnt;
            while(i<row and i>=0 and j<col and j>=0  and j<=right and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                ans.push_back(matrix[i][j]);
                cnt++;
                if(j==right) break;
                else
                j++;
               
            }
            right--;
            i++;
            while(j<col and j>=0 and i<row and i>=0  and i<=down  and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                ans.push_back(matrix[i][j]);
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
                ans.push_back(matrix[i][j]);
                cnt++;
                if(j==left) break;
                else
                j--;
                      }
               
            i--;
                left++;
            while(j<col and j>=0 and i<row and i>=0  and i>=up and mpp[{i,j}] == 0){
                ++mpp[{i,j}];
                     ans.push_back(matrix[i][j]);
                     cnt++;
                     if(i==up) break;
                     else
                     i--;
                    }
                 
            j++;
            if(cnt == tmp) break;
            up++;
    }
        // cout << i<<" "<<j;
            return ans;
    }
};