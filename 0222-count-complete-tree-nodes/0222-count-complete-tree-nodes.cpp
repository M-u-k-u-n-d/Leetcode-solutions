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
//     Solution in O(n) Time Complexity
    void preorder(TreeNode* root, int &ans){
        if(root == NULL) return;
        ans++;
        if(root->left)  preorder(root->left,ans);
        if(root->right) preorder(root->right, ans);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        preorder(root,ans);
        return ans;
    }
};