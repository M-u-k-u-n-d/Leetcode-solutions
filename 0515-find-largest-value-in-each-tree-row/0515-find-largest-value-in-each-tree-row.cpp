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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int num = INT_MIN;
            
            int n = q.size();
            while(n--){
                auto value = q.front();
                
                num = max(num,value->val);
                q.pop();
                if(value->left) q.push(value->left);
                if(value->right) q.push(value->right);
            }
            
            ans.push_back(num);
        }
        
        return ans;
    }
};