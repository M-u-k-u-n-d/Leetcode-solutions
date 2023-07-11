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
    void marked_parent(unordered_map<TreeNode* , TreeNode*> &parent, TreeNode* root,TreeNode* prev){
        if(root == NULL) return;
        parent[root] = prev;
        if(root->left) marked_parent(parent,root->left,root);
        if(root->right) marked_parent(parent,root->right,root);
    }
    void f(TreeNode* root,unordered_map<TreeNode*,TreeNode*>parent,int k,unordered_map<TreeNode*,int>&vis,vector<int> &ans,int cnt){
        if(root == NULL || vis[root] > 0) return;
        vis[root]++;
         if(cnt == k){
             ans.push_back(root->val);
             return;
            }
        if(vis[parent[root]] == 0){
           f(parent[root],parent,k,vis,ans,cnt+1);
        }
        if(root->left){
             f(root->left,parent,k,vis,ans,cnt+1);
        }
        if(root->right){
             f(root->right,parent,k,vis,ans,cnt+1);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        TreeNode* prev = NULL;
        marked_parent(parent,root,prev);
        vector<int> ans;
        unordered_map<TreeNode*,int>vis;
        f(target,parent,k,vis,ans,0);
        return ans;
    }
};