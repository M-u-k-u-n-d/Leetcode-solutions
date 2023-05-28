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
    TreeNode* searchNode(TreeNode* &root, int val){
        if(root == NULL || root->val == val) return root;
        else if(root->val > val) {
            root = root->left;
            searchNode(root,val);
        }
        else {
            root = root->right;
            searchNode(root,val);
        }
        return root;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchNode(root,val);
    }
};