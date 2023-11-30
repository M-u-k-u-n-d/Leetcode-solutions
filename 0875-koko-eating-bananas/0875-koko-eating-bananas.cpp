class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int l = 0, r = *max_element(piles.begin(),piles.end());
        
        while(l<r){
            int mid = l + (r-l) / 2;
            
            if(mid == 0) break;
            long long sum = 0;
            for(auto  it : piles){
                sum += ceil(1.0 * it / mid);
            }
            
            if(sum > h) l = mid+1;
            else r = mid;
        }
        
        return r;
    }
};