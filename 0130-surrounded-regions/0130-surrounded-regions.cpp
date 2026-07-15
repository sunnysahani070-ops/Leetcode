class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        
        // 1. Scan borders, mark 'O's as 'T', and add to queue
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'T';
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = 'T';
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = 'T';
            }
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = 'T';
            }
        }
        
        // Direction vectors for moving up, down, left, right
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        
        // 2. Process the queue (BFS)
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Check all 4 adjacent neighbors
            for (int k = 0; k < 4; k++) {
                int nr = r + dirX[k];
                int nc = c + dirY[k];
                
                // If within bounds and is an 'O', it's safe!
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O') {
                    board[nr][nc] = 'T'; // Mark as safe
                    q.push({nr, nc});    // Add to queue to check its neighbors
                }
            }
        }
        
        // 3. Final board translation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Captured
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // Restored
                }
            }
        }
    }
};