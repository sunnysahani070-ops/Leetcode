#include <vector>
#include <algorithm>

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* curr = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            int opposite_bit = 1 - bit;
            
            if (curr->children[opposite_bit]) {
                max_xor |= (1 << i);
                curr = curr->children[opposite_bit];
            } else {
                curr = curr->children[bit];
            }
        }
        return max_xor;
    }

public:
    int findMaximumXOR(std::vector<int>& nums) {
        root = new TrieNode();

        for (int num : nums) {
            insert(num);
        }
        int maxXor = 0;
        for (int num : nums) {
            maxXor = std::max(maxXor, getMaxXOR(num));
        }

        return maxXor;
    }
};