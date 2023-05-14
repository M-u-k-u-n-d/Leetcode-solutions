//Backtracking
class Solution {
public:
    void fun(int idx,int k,int &res,vector<int>& nums,vector<int>& ds,int n){
        if(k>n/2 or idx>=n){
            vector<int> vec=ds;
            sort(vec.begin(),vec.end());
            int ans=0;
            for(int i=0;i<vec.size();i++){
                ans+=(i+1)*vec[i];
            }
            res=max(res,ans);
            return;
        }
        if(nums[idx]){
            for(int i=idx+1;i<n;i++){
                if(nums[i] == 0) continue;//if the index was previously chosen then just skip it
                 //take the current number and change it to 0
                int temp=nums[i];
                nums[i]=0;
                ds.push_back(__gcd(nums[idx],temp));
                fun(idx+1,k+1,res,nums,ds,n);
                ds.pop_back();
                nums[i]=temp;
            }
        }
        else{
            fun(idx+1,k,res,nums,ds,n);
        }
    }
    int maxScore(vector<int>& nums) {
        int res=0;
        vector<int> ds;
        fun(0,1,res,nums,ds,nums.size());
        return res;
    }
};