class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            while (j < common.size() &&
                   j < strs[i].size() &&
                   common[j] == strs[i][j]) {
                j++;
            }

            common.erase(j);

            if (common.empty())
                return "";
        }

        return common;
    }
};