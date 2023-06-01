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
    void f(TreeNode* root,vector<TreeNode*> &v){
        if(root == NULL) return;
          v.push_back(root);
        if(root->left) f(root->left,v);
        if(root->right) f(root->right,v);
        return;
    }
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
       vector<TreeNode*> v;
        f(root,v);
        root = v[0];
        TreeNode* prev = root;
        for(int i=1; i<v.size(); i++){
            
            TreeNode* curr = v[i];
            prev->right = curr;
            prev->left = NULL;
            prev = curr;
            // cout << curr->val <<" "<<prev->val<<endl;
        }
    }
};