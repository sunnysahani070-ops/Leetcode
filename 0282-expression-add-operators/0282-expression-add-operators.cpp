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
        // Base case: reached the end of the string
        if (index == num.length()) {
            if (currentVal == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); ++i) {
            // Prevent numbers with leading zeros (e.g., "05")
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long curr = stol(part);

            // If it's the first number in the expression
            if (index == 0) {
                backtrack(num, target, i + 1, curr, curr, part, result);
            } else {
                // Addition
                backtrack(num, target, i + 1, currentVal + curr, curr, path + "+" + part, result);
                
                // Subtraction
                backtrack(num, target, i + 1, currentVal - curr, -curr, path + "-" + part, result);
                
                // Multiplication: Adjust for operator precedence by undoing the previous operation
                backtrack(num, target, i + 1, currentVal - prevNum + (prevNum * curr), prevNum * curr, path + "*" + part, result);
            }
        }
    }
};