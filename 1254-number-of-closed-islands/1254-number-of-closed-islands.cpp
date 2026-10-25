class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If we reach the boundary, this island touches the border and is NOT closed.
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1) or already visited, it's bounded.
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark current cell as visited by changing it to 1
        grid[r][c] = 1;
        
        // Traverse all 4 directions
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        
        // The island is closed only if all four directions are validly surrounded by water
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslands = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we find an unvisited land cell (0)
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid)) {
                        closedIslands++;
                    }
                }
            }
        }
        
        return closedIslands;
    }
};