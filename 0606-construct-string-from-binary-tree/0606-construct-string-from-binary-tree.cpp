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
    
    void f(TreeNode* root, string &ans, bool flag){
        if(flag) {
        ans += to_string(root->val);
        flag = false; }
        else{
            ans += "("  + to_string(root->val);
        }

        if(root->left) f(root->left,ans,flag);
        else if(root->right) ans += "()";
        
        if(root->right) f(root->right,ans,flag);
        
        ans += ")";
        
        // cout << ans <<" ";
    }
    
public:
    string tree2str(TreeNode* root) {
        string ans;
        bool flag = true;
        f(root,ans,flag);
        ans.pop_back();
        return ans;
    }
};