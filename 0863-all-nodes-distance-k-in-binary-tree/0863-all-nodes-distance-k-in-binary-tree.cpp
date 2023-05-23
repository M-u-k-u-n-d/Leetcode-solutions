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
    void mark_parent(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<TreeNode* , TreeNode*> parent;
        mark_parent(root,parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        // visited[target] = true;
        int cnt = 0;
        while(!q.empty()){
            if(cnt++ == k) break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(parent[current] and !visited[current]){
                    q.push(parent[current]);
                    visited[current] = true;
                }
                if(current->left and !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right and !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};