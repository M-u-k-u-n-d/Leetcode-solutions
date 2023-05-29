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
    void preorder(TreeNode* &root, vector<int> &arr){
        if(root == NULL) return;
        arr.push_back(root->val);
        if(root->left) preorder(root->left,arr);
        if(root->right) preorder(root->right,arr);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        preorder(root,arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};