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
    void constructPreorder(int key,TreeNode* &root){
        if(root->val > key){
            if(root->left == NULL){
                TreeNode* tmp = new TreeNode(key);
                root->left = tmp;
                return;
            }
            else {
                constructPreorder(key,root->left);
            }
        }
        else {
            if(root->right == NULL){
                TreeNode* tmp = new TreeNode(key);
                root->right = tmp;
                return;
            }
            else {
                constructPreorder(key,root->right);
            }
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++)
        constructPreorder(preorder[i],root);
        return root;
    }
};