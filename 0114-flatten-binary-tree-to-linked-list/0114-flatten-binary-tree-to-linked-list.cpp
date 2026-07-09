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
    void pre(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);

    }
public:
    void flatten(TreeNode* root) {
        vector<int> ans;
        pre(root,ans);
        TreeNode* curr = root;
for(int i = 1; i < ans.size(); i++) {
    if(root == NULL) return;
    curr->left = NULL;
    curr->right = new TreeNode(ans[i]);
    curr = curr->right;
}
        
        
    }
};