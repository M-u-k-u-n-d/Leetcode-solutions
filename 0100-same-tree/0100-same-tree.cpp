/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool preordercheck(TreeNode* p, TreeNode* q, bool &flag){
        if(p == NULL and q == NULL) return flag;  
        if(p == NULL || q == NULL ||(p->val != q->val)){
            flag = false;
            return flag;
        }
        preordercheck(p->left,q->left,flag);
        preordercheck(p->right,q->right,flag);
        return flag;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        return preordercheck(p,q,flag);
    }
};