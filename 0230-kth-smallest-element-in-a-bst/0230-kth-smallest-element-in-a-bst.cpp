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
//     IN INORDER TRAVERSAL FOR BST IT GIVES ELEMENT IN SORTED ORDER
    void inorder(TreeNode* &root, int k , vector<int>&arr){
        if(root == NULL) return;
           if(root->left){
            inorder(root->left, k,arr);
           }
             arr.push_back(root->val);
        if(root->right) {
            inorder(root->right,k,arr);
            }
        return ;    
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
         inorder(root,k,arr);
        // for(auto it : arr) cout << it <<" ";
        // cout << endl;
        return arr[k-1];
    }
};