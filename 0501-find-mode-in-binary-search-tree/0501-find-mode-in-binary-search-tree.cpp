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
    void inorder(TreeNode* root, map<int,int> &mpp){
        if(root == NULL) return;
        mpp[root->val]++;
        if(root->left) inorder(root->left,mpp);
        if(root->right) inorder(root->right,mpp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> mpp;
        inorder(root,mpp);
        vector<int> ans;
        int mx = INT_MIN;
        for(auto it : mpp){
            mx = max(mx,it.second);
        }
        
        for(auto it : mpp){
            if(it.second == mx){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};