class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int arr[3], ans = 0;
        arr[0] = a, arr[1] = b, arr[2] = c;
        sort(arr,arr+3);
        while(arr[1] != 0 and arr[2] != 0){
            ans++;
            arr[1]--,arr[2]--;
            sort(arr,arr+3);
        }
        return ans;
    }
};