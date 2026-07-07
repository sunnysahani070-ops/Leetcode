class Solution {
    void mx(TreeNode* root, int &depth, int level) {
        if (root == NULL) {
            depth = max(depth, level);
            return;
        }

        mx(root->left, depth, level + 1);
        mx(root->right, depth, level + 1);
    }

public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int depth = 0;
        mx(root, depth, 0);
        return depth;
    }
};