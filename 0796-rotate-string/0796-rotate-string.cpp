class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string doubled = goal + goal;

        return doubled.find(s) != string::npos;
    }
};