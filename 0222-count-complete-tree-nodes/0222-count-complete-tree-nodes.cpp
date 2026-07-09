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
    void in(TreeNode* root,vector<int>& ans,int& cnt){
        if(root==NULL){
            return;
        }
        cnt++;
        in(root->left,ans,cnt);
        ans.push_back(root->val);
        in(root->right,ans,cnt);
    }
public:
    int countNodes(TreeNode* root) {
        int cnt=0;
        vector<int> ans;
        in(root,ans,cnt);
        return cnt;
        
    }
};