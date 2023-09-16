class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int sum = 0;
        map<int,int> add,substract;
        
        for(auto it : trips){
           add[it[1]] += it[0];
           substract[it[2]] += it[0]; 
        }
        
        for(int i=0; i<= 1000; i++){
            sum -= substract[i];
            sum += add[i];
            
            if(sum > capacity) return false;
        }
        
        return true;   
    }
};