class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long current_val = 1;
        
        for (int k = 1; k < rowIndex; k++) {
            current_val = current_val * (rowIndex - k + 1) / k;
            row[k] = current_val;
        }
        
        return row;
    }
};