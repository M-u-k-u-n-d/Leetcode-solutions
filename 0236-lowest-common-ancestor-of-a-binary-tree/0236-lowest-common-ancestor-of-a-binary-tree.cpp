/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void f(TreeNode* root, TreeNode* p,vector<TreeNode*> &vpp, bool &flg){
        if(root == NULL || flg) return;
        vpp.push_back(root);
        if(root == p){
            flg = 1;
            return;
        }
        f(root->left,p,vpp,flg);
        f(root->right,p,vpp,flg);
        if(flg) return;
        vpp.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathp,pathq;
        bool flg = 0;
        f(root,p,pathp,flg);
        flg = 0;
        f(root,q,pathq,flg);
        for(int i=0;i<min(pathp.size(),pathq.size());i++){
            if(pathp[i]->val != pathq[i]->val) return pathp[i-1];
        }
        return pathp[min(pathp.size(),pathq.size())-1];
    }
};