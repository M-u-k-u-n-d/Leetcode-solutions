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
   void insertAtHead(ListNode* &tail , int d){
        ListNode* temp = new ListNode(d);
        tail -> next = temp;
        tail = temp;
    }
public:
    void reorderList(ListNode* head) {
        vector<int>v;
        ListNode* tmp = head;
        while(tmp != NULL){
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        int l=0, r=v.size()-1;
        vector<int>a;
        while(l<=r){
            if(l==r){
                a.push_back(v[l]);
            }
            else{
                a.push_back(v[l]);
                a.push_back(v[r]);
            }
            l++,r--;
        }
        head ->val = a[0];
        head ->next = NULL;
        for(int i=1; i<a.size() ;i++){
            insertAtHead(head,a[i]);
        }
        // head = temp;
        // return head;
    }
};