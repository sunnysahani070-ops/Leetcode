class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        string rev = "";
        bool is_negative = (x < 0);
        int limit = is_negative ? 1 : 0;
        
        for (int i = s.length() - 1; i >= limit; i--) {
            rev += s[i];
        }
        
        int start = 0;
        while (start < rev.length() && rev[start] == '0') {
            start++;
        }
        rev = rev.substr(start);
        
        if (rev.empty()) {
            return 0;
        }
        
        if (is_negative) {
            rev = "-" + rev;
        }
        
        long long ans = stoll(rev);
        if (ans < INT_MIN || ans > INT_MAX) {
            return 0;
        }
        
        return ans;
    }
};