class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int>a;
        for(int i=0; i<deck.size(); i++){
            a.push_back(deck[i]);
            if(i!=deck.size()-1) a.push_back(-1);
        }
        bool f=1;
        int j=deck.size();
        while(f){
            f=0;
            for(int i=0;i<deck.size();i++){
                if(a[i] == -1){
                    a[i] = a[j];
                    j++;
                    f=1;
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<deck.size(); i++) ans.push_back(a[i]);
        return ans;
    }
};