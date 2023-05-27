class Solution {
    TreeNode* builtTree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&hashmap){
        if(instart > inend || prestart > preend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = hashmap[root->val];
        int numsleft = inroot - instart;
        root->left = builtTree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,hashmap);
        root->right = builtTree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,hashmap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hashmap;
       for(int i=0; i<inorder.size(); i++){
           hashmap[inorder[i]] = i;
       }
        return builtTree(preorder, 0, preorder.size()-1, inorder , 0 , inorder.size()-1, hashmap);
    }
};