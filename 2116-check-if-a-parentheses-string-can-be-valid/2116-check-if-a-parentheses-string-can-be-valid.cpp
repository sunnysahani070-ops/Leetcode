class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false;

        int minOpen = 0, maxOpen = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                maxOpen++;
                minOpen = max(0, minOpen - 1);
            } else if (s[i] == '(') {
                maxOpen++;
                minOpen++;
            } else {
                maxOpen--;
                minOpen = max(0, minOpen - 1);
            }
            if (maxOpen < 0) return false;
        }
        return minOpen == 0;
    }
};