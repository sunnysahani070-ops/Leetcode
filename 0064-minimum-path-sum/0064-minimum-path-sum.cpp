class Solution {
    int memo[201][201]; 

    int solve(int r, int c, int m, int n, vector<vector<int>>& grid) {
        
        if (r == m - 1 && c == n - 1) return grid[r][c];
        
        
        if (r >= m || c >= n) return 1e9;
        
        
        if (memo[r][c] != -1) return memo[r][c];
        
        
        return memo[r][c] = grid[r][c] + min(solve(r + 1, c, m, n, grid), 
                                             solve(r, c + 1, m, n, grid));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                memo[i][j] = -1;
                
        return solve(0, 0, m, n, grid);
    }
};