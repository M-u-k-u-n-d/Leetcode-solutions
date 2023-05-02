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
    int f(TreeNode* root,bool &flg){
        // if(!flg) return 0;
        if(root == NULL) {
            return 0;
        }
        int lft = f(root->left,flg);
        int rgt = f(root->right,flg);
        if(abs(lft-rgt) > 1) flg = 0;
        return 1+max(lft,rgt);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flg = 1;
         f(root,flg);
        return flg;
    }
};