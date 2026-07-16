class Solution {
private:
    void bfs(int ro, int co, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[ro][co] = 1;
        queue<pair<int, int>> q;
        q.push({ro, co});
        

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
     
            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                
               
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    grid[nr][nc] == '1' && !vis[nr][nc]) {
                    
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        
        return count;
    }
};