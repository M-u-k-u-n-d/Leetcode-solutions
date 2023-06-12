class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        if(nums.size() == 0) return s;
        else if(nums.size() == 1) {
            s.push_back(to_string(nums[0]));
            return s;
        }
        int a = nums[0], b= -1;
        
        
        for(int i=1; i<nums.size(); i++){
            long long x = nums[i], y = nums[i-1];
            if(x-y != 1){
                b = nums[i-1];
                if(a==b){
                    string st;
                    st = to_string(a);
                    s.push_back(st);
                }
                else{
                    string st;
                    st = to_string(a) + "->" + to_string(b);
                    s.push_back(st);
                }
                a = nums[i];
                if(i==nums.size()-1){
                    string st;
                    st = to_string(a);
                    s.push_back(st);
                }
            }
            else if(i==nums.size()-1){
                b = nums[i];
                    string st;
                    st = to_string(a) + "->" + to_string(b);
                    s.push_back(st);
                
            }
        }
        return s;
    }
};