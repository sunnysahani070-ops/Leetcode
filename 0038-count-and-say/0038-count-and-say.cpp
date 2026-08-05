#include <string>

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string current = "1";

        for (int i = 2; i <= n; ++i) {
            string nextStr = "";
            int count = 1;

            for (int j = 1; j < current.length(); ++j) {
                if (current[j] == current[j - 1]) {
                    count++;
                } else {
                    nextStr += to_string(count) + current[j - 1];
                    count = 1;
                }
            }
            nextStr += to_string(count) + current.back();

            current = nextStr;
        }

        return current;
    }
};