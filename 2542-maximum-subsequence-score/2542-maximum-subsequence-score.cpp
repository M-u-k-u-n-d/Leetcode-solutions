class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
         // Creates a min heap
         priority_queue <int,vector<int>, greater<int>> pq;
        int n = nums1.size();
         vector<pair<int,int>> vpp;
        for(int i=0; i<n; i++){
            vpp.push_back({nums2[i],nums1[i]});
        }
        sort(vpp.begin(),vpp.end(),greater<>());
        int i=0;
        long long current_sum = 0;
        while(i<k){
            pq.push(vpp[i].second);
            current_sum += vpp[i].second;
            i++;
        }
        long long ans = current_sum * vpp[k-1].first;
        for(i=k; i<n; i++){
            pq.push(vpp[i].second);
            current_sum -= pq.top();
            pq.pop();
            current_sum += vpp[i].second;
            ans = max(ans,current_sum * vpp[i].first);
        }
        return ans;
    }
};