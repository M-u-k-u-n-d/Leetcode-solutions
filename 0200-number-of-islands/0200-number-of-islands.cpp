class Solution {
    bool left(int row,int col,vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(col>0 and grid[row][col-1] == '1') return true;
        return false;
    }
     bool right(int row,int col,vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(col<n-1 and grid[row][col+1] == '1') return true;
        return false;
    }
     bool up(int row,int col,vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(row>0 and grid[row-1][col] == '1') return true;
        return false;
    }
    bool down(int row,int col,vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(row<m-1 and grid[row+1][col] == '1') return true;
        return false;
    }
    void bfs(int rw,int cl,vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({rw,cl});
        while(!q.empty()){
            auto curr = q.front();
            int row = curr.first;
            int col = curr.second;
            q.pop();
            if(up(curr.first,curr.second,grid)){
                 grid[row-1][col] = '2';
                q.push({row-1,col});
            }
            if(down(curr.first,curr.second,grid)){
                grid[row+1][col] = '2';
                q.push({row+1,col});
            }
            if(left(curr.first,curr.second,grid)){
                grid[row][col-1] = '2';
                q.push({row,col-1});
            }
            if(right(curr.first,curr.second,grid)){
                grid[row][col+1] = '2';
                q.push({row,col+1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '2';
                    bfs(i,j,grid);
                }
            }
        }
           return ans; 
    }
};