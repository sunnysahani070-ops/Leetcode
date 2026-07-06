#include <algorithm>

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char ch : num) {
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res;

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        while (!res.empty() && res[0] == '0') {
            res.erase(0, 1);
        }

        return res.empty() ? "0" : res;
    }
};