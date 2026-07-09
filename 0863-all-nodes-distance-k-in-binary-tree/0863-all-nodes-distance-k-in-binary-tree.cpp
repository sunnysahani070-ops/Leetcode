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
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parents_track,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=nullptr){
                parents_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                parents_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents_track;
        markparents(root,parents_track,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int currlevel=0;
        while(!q.empty()){
            int size=q.size();
            if(currlevel++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();q.pop();
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parents_track[curr] && !visited[parents_track[curr]]){
                    visited[parents_track[curr]]=true;
                    q.push(parents_track[curr]);
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr=q.front();q.pop();
            result.push_back(curr->val);
        }
        return result;


        
    }
};