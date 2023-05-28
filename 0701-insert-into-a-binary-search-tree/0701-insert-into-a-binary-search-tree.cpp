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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* newroot = new TreeNode(val);
        if(root == NULL){
            return newroot;
        }
        TreeNode* prev = root;
        TreeNode* tmp = root;
        while(1){
            if(tmp == NULL){
                if(prev->val > val){
                    prev->left = newroot;
                    return root;
                }
                else{    
                    prev->right = newroot;
                    return root;
                }
            }
            else if(tmp->val > val) {
                prev = tmp;
                tmp = tmp->left;
            }
            else {
                prev = tmp;
                tmp = tmp->right;
            }
        }
        return root;
    }
};