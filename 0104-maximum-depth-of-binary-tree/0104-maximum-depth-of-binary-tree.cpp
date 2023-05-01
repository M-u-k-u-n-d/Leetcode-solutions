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
    
public:
    int maxDepth(TreeNode* root) {
          int ans = 1;
          queue<TreeNode*> q;
         if(root == NULL) return 0;
            q.push(root);
        while(!q.empty()){
            queue<TreeNode*>v;
            while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->left != NULL ) v.push(root->left);
            if(root->right != NULL) v.push(root->right);
            }
            if(v.size() > 0){
                ans++;
                while(!v.empty()){
                    q.push(v.front());
                    v.pop();
                }
            }
        }
        return ans;
    }
};