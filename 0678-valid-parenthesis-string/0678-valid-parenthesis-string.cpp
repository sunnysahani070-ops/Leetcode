class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;

        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--; // treating * as ')'
                max_open++; // treating * as '('
            }

            // If max_open is negative, there are too many ')' to ever be balanced
            if (max_open < 0) return false;

            // min_open cannot be negative because we can't have "negative" open brackets.
            // If it goes negative, it just means we assumed too many '*' were ')', so we reset it to 0.
            if (min_open < 0) min_open = 0;
        }

        // If min_open is 0, it means we can form a perfectly valid string
        return min_open == 0;
    }
};