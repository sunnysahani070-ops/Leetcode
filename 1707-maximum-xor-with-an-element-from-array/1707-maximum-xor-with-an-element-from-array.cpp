#include <vector>
#include <algorithm>

using namespace std;

// Trie Node Structure
struct TrieNode {
    TrieNode* children[2] = {nullptr, nullptr};
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a number into the Trie (using 31 bits)
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    // Find the maximum XOR value possible with `num`
    int getMaxXor(int num) {
        TrieNode* curr = root;
        // If Trie is empty (no valid elements inserted)
        if (!curr->children[0] && !curr->children[1]) {
            return -1;
        }

        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            // Try to take the opposite bit path to maximize XOR
            if (curr->children[oppositeBit]) {
                maxXor |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // Store queries with original indices: {m_i, x_i, original_index}
        vector<vector<int>> offlineQueries(q);
        for (int i = 0; i < q; ++i) {
            offlineQueries[i] = {queries[i][1], queries[i][0], i};
        }

        // Sort nums and queries in ascending order
        sort(nums.begin(), nums.end());
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> ans(q);
        int numsIdx = 0;

        // Process each query
        for (int i = 0; i < q; ++i) {
            int m = offlineQueries[i][0];
            int x = offlineQueries[i][1];
            int originalIdx = offlineQueries[i][2];

            // Insert all nums <= m into the Trie
            while (numsIdx < n && nums[numsIdx] <= m) {
                trie.insert(nums[numsIdx]);
                numsIdx++;
            }

            // Query the Trie for the max XOR
            ans[originalIdx] = trie.getMaxXor(x);
        }

        return ans;
    }
};