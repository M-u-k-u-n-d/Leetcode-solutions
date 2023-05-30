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
TreeNode* f(queue<TreeNode*>&Q,TreeNode* root){
    if(root == NULL) return NULL;
    if(root->left) f(Q,root->left);
    Q.push(root);
    if(root->right) f(Q,root->right);
    return root;
}
class BSTIterator {
    queue<TreeNode*>Q;
public:
    BSTIterator(TreeNode* root) {
      root = f(Q,root);
    }
    
    int next() {
        // cout<<Q.front()->val<<" ";
        TreeNode* cur = Q.front();
        Q.pop();
        return cur->val;
        // return 0;
    }
    
    bool hasNext() {
        return !Q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */