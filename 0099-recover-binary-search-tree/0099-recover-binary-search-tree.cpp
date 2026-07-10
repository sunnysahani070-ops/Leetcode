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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pred = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (pred != nullptr && pred->val > curr->val) {
                    if (first == nullptr) first = pred;
                    second = curr;
                }
                pred = curr;
                curr = curr->right;
            } else {
                TreeNode* tmp = curr->left;
                while (tmp->right != nullptr && tmp->right != curr) {
                    tmp = tmp->right;
                }

                if (tmp->right == nullptr) {
                    tmp->right = curr;
                    curr = curr->left;
                } else {
                    tmp->right = nullptr;
                    if (pred != nullptr && pred->val > curr->val) {
                        if (first == nullptr) first = pred;
                        second = curr;
                    }
                    pred = curr;
                    curr = curr->right;
                }
            }
        }

        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};