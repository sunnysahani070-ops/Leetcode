class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0}; 
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> v;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                v.push_back({freq[i], (char)i});
            }
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string result;
        result.reserve(s.size()); 
        
        for (auto& p : v) {
            result.append(p.first, p.second); 
        }

        return result;
    }
};