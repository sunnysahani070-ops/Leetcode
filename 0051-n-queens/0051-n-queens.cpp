class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, 0, 0, 0, board, ans);
        return ans;
    }
    
private:
    void solve(int row, int n, int cols, int diag1, int diag2, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        
        while (availablePositions) {
            int pos = availablePositions & -availablePositions; 
            availablePositions &= availablePositions - 1; 
            int colIndex = __builtin_ctz(pos); 
            board[row][colIndex] = 'Q';
            solve(row + 1, n, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1, board, ans);
            board[row][colIndex] = '.';
        }
    }
};