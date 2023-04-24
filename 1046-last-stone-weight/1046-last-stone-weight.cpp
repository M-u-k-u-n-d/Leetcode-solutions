class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1){
            int i = stones.size()-1;
            if(stones[i] != stones[i-1]){
                int x = (stones[i]-stones[i-1]);
                  stones.pop_back();
                  stones.pop_back();
                stones.push_back(x);
                sort(stones.begin(),stones.end());
            }
            else{
            stones.pop_back();
            stones.pop_back();
            }
        }
        if(stones.size()==0) return 0;
        return stones[0];
    }
};