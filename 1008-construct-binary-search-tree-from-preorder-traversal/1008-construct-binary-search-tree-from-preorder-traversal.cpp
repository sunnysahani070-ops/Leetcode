/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            insertIntoBST(root, preorder[i]);
        }

        return root;
    }
};