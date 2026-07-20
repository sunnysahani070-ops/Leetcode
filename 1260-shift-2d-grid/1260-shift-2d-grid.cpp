class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Handle cases where k is greater than the total number of elements
        k = k % totalElements;
        if (k == 0) return grid;

        vector<vector<int>> copy(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Convert 2D coordinate (i, j) to a 1D flat index
                int flatIndex = i * n + j;
                
                // Shift the flat index by k positions cyclically
                int newFlatIndex = (flatIndex + k) % totalElements;
                
                // Convert the new 1D index back to 2D coordinates
                int newRow = newFlatIndex / n;
                int newCol = newFlatIndex % n;
                
                copy[newRow][newCol] = grid[i][j];
            }
        }
        return copy;
    }
};