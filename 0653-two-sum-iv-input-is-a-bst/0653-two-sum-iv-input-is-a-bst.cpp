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
    unordered_set<int> st;

    bool dfs(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};