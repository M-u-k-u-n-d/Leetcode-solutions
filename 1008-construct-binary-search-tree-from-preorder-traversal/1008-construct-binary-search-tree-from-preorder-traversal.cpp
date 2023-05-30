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
    TreeNode* f(vector<int>preorder,int prestart,int preend,vector<int>inorder,int instart,int inend,map<int,int>mpp){
        if(prestart > preend || instart > inend) return NULL;
        int inroot = mpp[preorder[prestart]];
        int numsleft = inroot - instart;
        TreeNode* root = new TreeNode(inorder[inroot]);
        root->left = f(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
        root->right = f(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mpp);
        return root;
    }
   
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int instart = 0, inend = inorder.size()-1, prestart = 0, preend = preorder.size()-1;
        // TreeNode* root = new TreeNode(preorder[0]);    
        map<int,int>mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
       return f(preorder,prestart,preend,inorder,instart,inend,mpp);
    }
};