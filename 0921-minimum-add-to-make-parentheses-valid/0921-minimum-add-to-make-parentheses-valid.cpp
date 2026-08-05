class Solution {
public:
    int minAddToMakeValid(string s) {
        int unmatchedOpen = 0;
        int unmatchedClose = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                unmatchedOpen++;
            } else if (s[i] == ')') {
                if (unmatchedOpen > 0) {
                    unmatchedOpen--; 
                } else {
                    unmatchedClose++; 
                }
            }
        }
        return unmatchedOpen + unmatchedClose;
    }
};