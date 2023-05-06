class Solution {
    long long power(long long a, unsigned int b, long long c){
    long long  res = 1;
    a %= c;
    if(a == 0) return 0;
    while(b > 0){
    if(b & 1){
        res = (res % c * a % c) % c;
    }

    b = b >> 1;
    a =( a % c * a % c) % c;
    }
    return res % c;
}
    int find_index(vector<int>& a,int num, int l , int r, int target){
        int mid = l+(r-l)/2,ind = -1;
        while(l<=r){
            if(num+a[mid] <= target) {
                ind = mid;
                l = mid+1;
            }
            else  r=mid-1;
            mid = l+(r-l)/2;
        }
       
        return ind;
    }
public:
    long long numSubseq(vector<int>& nums, int target) {
        const int mod = 1000000007;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0; i<n; i++){
            int ind = find_index(nums,nums[i],i,n-1,target);
            // cout << ind <<" ";
            if(ind == -1) break;
            else{
                // cout << ind-i+1<<" "<<ind-i<<endl;
                // cout << pow(2,ind-i+1) <<" "<<pow(2,ind-i)<<endl;
                long long n1 =   power(2,ind-i,mod);
                
                // cout << n1 <<" "<<n2<<endl;
                ans = (ans%mod +( n1) %mod)%mod;
                // ans %= mod;
            }
        }
        return ans;
    }
};