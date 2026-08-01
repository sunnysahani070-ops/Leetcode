#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    bool parseBoolExpr(std::string expression) {
        std::stack<char> st;

        for (char c : expression) {
            if (c == ',') {
                continue;
            } else if (c != ')') {
                st.push(c);
            } else {
                
                std::vector<char> values;
                while (!st.empty() && st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                
               
                st.pop();
                
                
                char op = st.top();
                st.pop();

                
                char result = evaluate(op, values);
                st.push(result);
            }
        }

        return st.top() == 't';
    }

private:
    char evaluate(char op, const std::vector<char>& values) {
        if (op == '!') {
            return values[0] == 't' ? 'f' : 't';
        } else if (op == '&') {
            for (char v : values) {
                if (v == 'f') return 'f';
            }
            return 't';
        } else { 
            for (char v : values) {
                if (v == 't') return 't';
            }
            return 'f';
        }
    }
};