#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }
        
        int maxLength = 0;
        
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.count(num)) {
                    int len = to_string(num).length();
                    maxLength = max(maxLength, len);
                    break;
                }
                num /= 10;
            }
        }
        
        return maxLength;
    }
};