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
    long long int widthOfBinaryTree(TreeNode* root) {
        long long int ans = 0;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long int mn = q.front().second;
            long long int lft,rgt;
            for(int i = 0; i < n; i++){
                TreeNode* node =  q.front().first;
                long long int curr_ind = q.front().second-mn;
                q.pop();
                if(i==0) lft = curr_ind;
                if(i==n-1) rgt = curr_ind;
                if(node->left){
                    q.push({node->left,2*curr_ind+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_ind+2});
                }
            }
            ans = max(rgt-lft+1,ans);
        }
        return ans;
    }
};