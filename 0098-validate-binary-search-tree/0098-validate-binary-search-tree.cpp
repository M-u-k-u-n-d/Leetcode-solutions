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
    bool f(TreeNode* root, long long lft, long long rgt ){
       if(root == NULL) return true;
        if(root->val >= rgt or root->val <= lft) return false;
         return f(root->left,lft,root->val) and f(root->right,root->val,rgt);
        // if(root->right) return f(root->right,root->val,rgt);
    }
public:
    bool isValidBST(TreeNode* root) {
     long long lft = INT_MIN, rgt = INT_MAX;
        rgt++;
        lft--;
        return  f(root,lft,rgt);
    }
};