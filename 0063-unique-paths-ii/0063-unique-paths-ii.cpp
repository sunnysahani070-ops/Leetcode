class Solution {
    int memo[101][101];

    int solve(int r, int c, int m, int n, const vector<vector<int>>& obstacleGrid) {

        if (r >= m || c >= n) return 0;

      
        if (obstacleGrid[r][c] == 1) return 0;

        
        if (r == m - 1 && c == n - 1) return 1;

       
        if (memo[r][c] != -1) return memo[r][c];

       
        return memo[r][c] = solve(r + 1, c, m, n, obstacleGrid) + solve(r, c + 1, m, n, obstacleGrid);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }

        return solve(0, 0, m, n, obstacleGrid);
    }
};