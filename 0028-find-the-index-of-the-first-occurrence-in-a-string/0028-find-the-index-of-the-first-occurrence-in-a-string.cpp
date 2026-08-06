#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        if (m > n) return -1;

        // Step 1: Build the Longest Prefix Suffix (LPS) array
        std::vector<int> lps(m, 0);
        int prevLPS = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[prevLPS]) {
                prevLPS++;
                lps[i] = prevLPS;
                i++;
            } else {
                if (prevLPS != 0) {
                    prevLPS = lps[prevLPS - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Perform the KMP search
        int h = 0; // Index for haystack
        int n_idx = 0; // Index for needle

        while (h < n) {
            if (haystack[h] == needle[n_idx]) {
                h++;
                n_idx++;
            }

            if (n_idx == m) {
                return h - m; // Found pattern at index h - m
            } else if (h < n && haystack[h] != needle[n_idx]) {
                if (n_idx != 0) {
                    n_idx = lps[n_idx - 1];
                } else {
                    h++;
                }
            }
        }

        return -1;
    }
};