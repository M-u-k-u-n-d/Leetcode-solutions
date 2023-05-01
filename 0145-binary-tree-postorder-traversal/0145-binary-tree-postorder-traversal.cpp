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
//     USING ONE STACK
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>ans;
       TreeNode*  curr = root;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                root = st.top()->right;
                if(root == NULL){
                    root = st.top();
                    ans.push_back(root->val);
                    st.pop();
                    while(!st.empty() and st.top() -> right == root){
                    root = st.top();
                    ans.push_back(root->val);
                    st.pop();
                    }
                }
                else{
                    curr = root;
                }
            }
        }
        return ans;
    }
};