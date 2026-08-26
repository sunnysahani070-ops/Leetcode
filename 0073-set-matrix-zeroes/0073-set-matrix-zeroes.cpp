class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool r0 = false, c0 = false;

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) { r0 = true; break; }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) { c0 = true; break; }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                fill(matrix[i].begin() + 1, matrix[i].end(), 0);
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) matrix[i][j] = 0;
            }
        }

        if (r0) fill(matrix[0].begin(), matrix[0].end(), 0);
        
        if (c0) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};