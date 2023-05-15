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
    void insertAtTail(ListNode* &tail , int d){
        ListNode* temp = new ListNode(d);
        tail -> next = temp;
        tail = temp;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return head;
        vector<int> a;
        while(head != NULL){
            a.push_back(head->val);
            head = head -> next;
        }
        int n = a.size();
        swap(a[k-1],a[n-k]);
         ListNode* newnode = new ListNode(a[0]);
         ListNode* newhead = newnode;
         ListNode* tail = newnode;
        for(int i=1; i<n; i++){
            insertAtTail(tail,a[i]);
        }
      return newhead;
    }
};