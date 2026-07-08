/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void chk(TreeNode* root, int row, int col,
             vector<tuple<int,int,int>>& nodes) {

        if(root == NULL)
            return;

        nodes.emplace_back(col, row, root->val);

        chk(root->left, row + 1, col - 1, nodes);
        chk(root->right, row + 1, col + 1, nodes);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<tuple<int,int,int>> nodes;

        chk(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        if(nodes.empty())
            return ans;

        int currCol = get<0>(nodes[0]);
        ans.push_back({});

        for(auto &t : nodes){

            int col = get<0>(t);
            int row = get<1>(t);
            int val = get<2>(t);

            if(col != currCol){
                currCol = col;
                ans.push_back({});
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};