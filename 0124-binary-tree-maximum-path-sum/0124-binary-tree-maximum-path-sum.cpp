class Solution {
    int ans = INT_MIN;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = max(0, height(root->left));
        int right = max(0, height(root->right));

        ans = max(ans, left + right + root->val);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        height(root);
        return ans;
    }
};