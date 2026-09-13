#include <vector>
#include <string>

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(const string& num, long target, int index, long currentVal, long prevNum, string path, vector<string>& result) {
        if (index == num.length()) {
            if (currentVal == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); ++i) {
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long curr = stol(part);

            if (index == 0) {
                backtrack(num, target, i + 1, curr, curr, part, result);
            } else {
                backtrack(num, target, i + 1, currentVal + curr, curr, path + "+" + part, result);
                
                backtrack(num, target, i + 1, currentVal - curr, -curr, path + "-" + part, result);
                backtrack(num, target, i + 1, currentVal - prevNum + (prevNum * curr), prevNum * curr, path + "*" + part, result);
            }
        }
    }
};