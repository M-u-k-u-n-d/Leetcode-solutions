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
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
         TreeNode* temp = findLastRight(root->left);
            temp->right = root->right;
            return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        else if(root->val == key){
            if(root->left == NULL) return root->right;
            else if(root->right == NULL) return root->left;
            TreeNode* temp = findLastRight(root->left);
            temp->right = root->right;
            return root->left;
        }
        else{
            TreeNode* curr = root;
            while(curr != NULL){
                if(curr->val > key){
                    if(curr->left != NULL and curr->left->val == key){
                        curr->left = helper(curr->left);
                        break;
                    }
                    else curr = curr->left;
                }
                else{
                    if(curr->right != NULL and curr->right->val == key){
                        curr->right = helper(curr->right);
                        break;
                    }
                    else curr = curr->right;
                }
            }
            return root;
        }
    }
};