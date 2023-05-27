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
     TreeNode* builtTree(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&hashmap){
        if(instart > inend || poststart > postend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = hashmap[root->val];
        int numsleft = inend-inroot;
        root->left = builtTree(postorder,0,postend-numsleft-1,inorder,instart,inroot-1,hashmap);
        root->right = builtTree(postorder,postend-numsleft,postend-1,inorder,inroot+1,inend,hashmap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hashmap;
       for(int i=0; i<inorder.size(); i++){
           hashmap[inorder[i]] = i;
       }
        return builtTree(postorder, 0, postorder.size()-1, inorder , 0 , inorder.size()-1, hashmap);
    }
};