class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> st;
        for(int i=0; i<heights.size()-1; i++){
                int num = heights[i+1]-heights[i];
            if(heights[i] < heights[i+1]){
                if(num <= bricks){
                    bricks -= num;  
                    st.push(num);
                }
                else{
                    if(ladders > 0 ){
                        if(st.empty()) ladders--;
                        else if(num > st.top()) ladders--;
                        else{
                        bricks += st.top();
                        st.pop();
                        ladders--;
                        bricks -= num;
                        st.push(num);
                        }
                    }
                    else{
                        return i;
                    }
                }
            }
        }
        
        return heights.size()-1;
    }
};