/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head!= 0){
            v.push_back(head->val);
            head=head->next;
        }
        int l=0, r = v.size()-1,ans=0;
        while(l<r){
            ans =max(v[l]+v[r],ans);
            l++;r--;
        }
        return ans;
    }
};