class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> height(cols, 0);
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            int current_left = 0, current_right = cols;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], current_left);
                } else {
                    left[j] = 0;
                    current_left = j + 1;
                }
            }
            for (int j = cols - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], current_right);
                } else {
                    right[j] = cols;
                    current_right = j;
                }
            }
            for (int j = 0; j < cols; ++j) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }
        }
        
        return maxArea;
    }
};