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
     ListNode* f(ListNode* &head,int k){
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        ListNode* temp = curr;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }       
        if(count >= k){
        int cnt = k;
        while(curr != NULL and cnt>0){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt--;
        }
        }
        else {
            return head;
        }
            head->next = f(forward,k);
        return prev;
        }
public:
    ListNode* swapPairs(ListNode* head) {
        return f(head,2);
    }
};