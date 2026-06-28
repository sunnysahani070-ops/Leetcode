class Solution {
    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // Base case: entire word matched
        if (index == word.size())
            return true;

        // Out of bounds
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size())
            return false;

        // Character doesn't match
        if (board[row][col] != word[index])
            return false;

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Backtrack (restore original character)
        board[row][col] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as the starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }

            }
        }

        return false;
    }
};