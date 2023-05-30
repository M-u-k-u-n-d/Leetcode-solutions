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

class BSTIterator {
    stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
     while(root != NULL) {
        st.push(root);
         root = root->left;
     }
    }
    
    int next() {
      TreeNode* curr = st.top();
        int num = curr->val;
        st.pop();
            if(curr->right){
                curr=curr->right;
                    while(curr != NULL) {
                        st.push(curr);
                        curr = curr->left;
                                   }
                    }
        return num;
        }
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */