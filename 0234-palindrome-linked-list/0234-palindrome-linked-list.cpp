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
    bool isPalindrome(ListNode* head) {
        string s;
        ListNode* root = head;
        while(root){
            s += to_string(root->val);
            root = root->next;
        }
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        return (tmp == s);
    }
};