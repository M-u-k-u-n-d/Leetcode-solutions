class Solution {
public:
    int totalMoney(int n) {
        int cnt = 1,ans=0,prev=-1;
        for(int i=1; i<=n; i++){
            if(i%7 == 1){
                ans += cnt;
                prev = cnt;
                cnt++;
            }
            else{
                ans += prev + 1;
                prev++;
            }
            
        }
        
        return ans;
    }
};