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
    int f(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int lft = f(root->left,ans);
        int rgt = f(root->right,ans);
                    ans = max(lft+rgt,ans);
        return 1+max(lft , rgt);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        f(root,ans);
        return ans;
    }
};