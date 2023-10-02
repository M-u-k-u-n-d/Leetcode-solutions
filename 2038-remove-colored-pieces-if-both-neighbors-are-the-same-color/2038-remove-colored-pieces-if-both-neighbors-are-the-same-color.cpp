class Solution {
public:
    bool winnerOfGame(string colors) {
        int A=0,B=0,cnta = 0 , cntb = 0;
        for(auto it : colors){
            if(it == 'A'){
                cnta++;
                B += max(cntb-2, 0);
                cntb = 0;
            }
            else{
                cntb++;
                A += max(cnta -2, 0);
                cnta = 0;
            }
        }
        A += max(cnta -2, 0);
        B += max(cntb-2, 0);
        return (A > B);
    }
};