class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();

        for (int shift = 0; shift < n; shift++) {
            string rotated(n, ' ');

            for (int j = 0; j < n; j++) {
                rotated[j] = goal[(j + shift) % n];
            }

            if (rotated == s) {
                return true;
            }
        }

        return false;
    }
};