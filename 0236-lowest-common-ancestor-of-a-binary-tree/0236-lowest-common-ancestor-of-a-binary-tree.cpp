/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL || root == p || root == q){
           return root;
       }
        auto lft = lowestCommonAncestor(root->left,  p,  q);
        auto rgt = lowestCommonAncestor(root->right,  p,  q);
        if(lft == NULL) return rgt;
        else if(rgt == NULL) return lft;
        else return root;
    }
};