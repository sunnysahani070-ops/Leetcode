#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Handle empty string edge case
        if (s.empty()) return 0; 
        
        int max_len = 0; // Renamed to avoid clashing with std::max
        
        for (int i = 0; i < s.size(); i++) {
            string sub = "";
            sub += s[i];
            int len = sub.size(); // Initialize len for single character cases
            
            for (int j = i + 1; j < s.size(); j++) {
                if (sub.contains(s[j])) {
                    break;
                } else {
                    sub += s[j];
                }
                len = sub.size(); // Update len continuously
            }
            max_len = max(max_len, len); // Fixed function usage
        }
        return max_len;
    }
};