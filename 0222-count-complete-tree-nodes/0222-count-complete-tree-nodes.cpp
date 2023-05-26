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
    int left_height(TreeNode* root){
        if(root == NULL) return 0;
        return 1+left_height(root->left);
    }
    int right_height(TreeNode* root){
        if(root == NULL) return 0;
        return 1+right_height(root->right);
    }
    int completeNodes(TreeNode* root){
        if(root == NULL) return 0;
        int lftheight = left_height(root->left);
        int rgtheight = right_height(root->right);
        if(lftheight == rgtheight) {
            // cout << lftheight <<" "<<rgtheight<<endl;
            int hgt = 1 + lftheight;
            int ans = pow(2,hgt) - 1;
            return ans;
        }
        else{
            return 1 + completeNodes(root->left) + completeNodes(root->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + completeNodes(root->left) + completeNodes(root->right);
    }
};