class Solution {
    bool up(int row, int col, int i , int j,vector<vector<int>>& grid){
        if(i > 0 and grid[i-1][j] == 1) return true;
        return false;
    }
    bool down(int row, int col, int i , int j,vector<vector<int>>& grid){
        if(i < row-1 and grid[i+1][j] == 1) return true;
        return false;
    }
    bool left(int row, int col, int i , int j,vector<vector<int>>& grid){
        if(j > 0 and grid[i][j-1] == 1) return true;
        return false;
    }
    bool right(int row, int col, int i , int j,vector<vector<int>>& grid){
        if(j < col-1 and grid[i][j+1] == 1) return true;
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // int vis[row][col] = {0};
        queue<pair<int,int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    // vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            bool f=0;
            for(int i=0; i<size; i++){
                pair<int,int> curr = q.front();
                q.pop();
            if(up(row,col,curr.first,curr.second,grid)){
                f=1;
                grid[curr.first-1][curr.second] = 2;
                q.push({curr.first-1,curr.second});
            }
            if(down(row,col,curr.first,curr.second,grid)){
                f=1;
                q.push({curr.first+1,curr.second});
                grid[curr.first+1][curr.second] = 2;
            }
            if(left(row,col,curr.first,curr.second,grid)){
                f=1;
                q.push({curr.first,curr.second-1});
                grid[curr.first][curr.second-1] = 2;
            }
            if(right(row,col,curr.first,curr.second,grid)){
                f=1;
                grid[curr.first][curr.second+1] = 2;
                q.push({curr.first,curr.second+1});
            }
            }
            if(f)
            ans++;
        }
        if(check(grid)) return -1;
        return ans;
    }
    bool check(vector<vector<int>>& grid){
        for(auto it : grid){
            for(auto nit : it){
                if(nit == 1) return 1;
            }
        }
        return 0;
    }
};