class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string token;
        int prev = -1;
        
        while (ss >> token) {
            if (isdigit(token[0])) {
                int num = stoi(token);
                if (num <= prev) {
                    return false;
                }
                prev = num;
            }
        }
        
        return true;
    }
};