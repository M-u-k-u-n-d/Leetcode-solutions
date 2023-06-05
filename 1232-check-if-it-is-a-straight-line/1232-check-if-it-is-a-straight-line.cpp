class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1],x2 = coordinates[1][0], y2 = coordinates[1][1];
        int a = x2-x1, b = y2-y1;
        for(int i=2; i<coordinates.size(); i++){
            int X = coordinates[i][0], Y = coordinates[i][1];
            if(X*b - Y*a != x1*b-y1*a) return false;
        }
        return true;
    }
};