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
    bool f(TreeNode* lft, TreeNode* rght, bool &ans){
    
        if((lft == NULL and rght != NULL) || (lft != NULL and rght == NULL)){
            ans = false;
            return ans;
        }
        if(lft == NULL) return ans;
        if(lft->val != rght->val){
            ans = false;
            return ans;
            }

        f(lft->left,rght->right,ans);
        f(lft->right,rght->left,ans);
        return ans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        bool ans = true;
        f(root->left,root->right,ans);
        return ans;
    }
};