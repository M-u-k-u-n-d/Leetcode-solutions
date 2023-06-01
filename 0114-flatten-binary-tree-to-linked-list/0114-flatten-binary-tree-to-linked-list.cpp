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
void    f(TreeNode* root, TreeNode* &prev){
        if(root == NULL) return;
        if(root->right) f(root->right,prev);
        if(root->left) f(root->left,prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return;
    }
   
public:
    void flatten(TreeNode* root) {
      TreeNode* prev = NULL;
      f(root,prev);
    }
};