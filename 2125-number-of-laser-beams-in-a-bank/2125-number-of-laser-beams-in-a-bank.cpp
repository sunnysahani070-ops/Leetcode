class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int prev = 0;
        
        for (const string& row : bank) {
            int curr = 0;
            for (char c : row) {
                if (c == '1') {
                    curr++;
                }
            }
            
            if (curr > 0) {
                total += prev * curr;
                prev = curr;
            }
        }
        
        return total;
    }
};