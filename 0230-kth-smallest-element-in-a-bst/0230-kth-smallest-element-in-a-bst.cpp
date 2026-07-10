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
    void pre(TreeNode* root,set<int>& ans){
        if(root==NULL){
            return;
        }
        ans.insert(root->val);
        pre(root->left,ans);
        pre(root->right,ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        set<int> ans;
        pre(root,ans);

        if(k>ans.size()){
            return -1;
        }
        auto it =next(ans.begin(), k-1);

        int element = *it; 
        return element;
        
    }
};