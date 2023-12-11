class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
                
        int target = floor((n*25*1.0)/100);
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1] ) cnt++;
            else{
                cnt = 1;
            }
            
            if(cnt > target) return arr[i];
        }
        
        return arr[0];
    }
};