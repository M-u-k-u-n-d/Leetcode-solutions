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
    int f(TreeNode* root, int min_value, int max_value){
        if(root == NULL) return max_value - min_value;
        int left = 0, right = 0;
        // cout <<min_value<<" "<<max_value<<endl;
            min_value = min(root->val , min_value);
            max_value = max(root->val, max_value);
           left = max(left,f(root->left,min_value,max_value));
           right = max(right,f(root->right,min_value,max_value));
        
        return max(left,right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return f(root,root->val, root->val);
    }
};