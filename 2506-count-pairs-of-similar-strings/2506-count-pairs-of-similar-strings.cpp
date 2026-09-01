class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mask_counts;
        int pairs = 0;
        
        for (const string& word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }
            pairs += mask_counts[mask];
            mask_counts[mask]++;
        }
        
        return pairs;
    }
};