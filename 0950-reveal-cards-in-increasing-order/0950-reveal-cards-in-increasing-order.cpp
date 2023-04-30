class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int>ans(n);
        deque<int>dq;
        for(int i=0; i<deck.size(); i++){
            dq.push_back(i);
        }
        int flip = 0, ind = 0;
        while(dq.size()>0){
            if(flip == 0){
                ans[dq.front()] = deck[ind++];
                dq.pop_front();
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
            flip ^= 1;
        }
        return ans;
    }
};