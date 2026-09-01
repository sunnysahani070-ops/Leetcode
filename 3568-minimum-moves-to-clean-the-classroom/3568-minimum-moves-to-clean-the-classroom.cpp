class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();
        int litterCount = 0;
        int startRow = -1, startCol = -1;
        vector<vector<int>> litterId(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0) return 0;
        
        int targetMask = (1 << litterCount) - 1;
        vector<vector<vector<int>>> maxEnergy(rows, vector<vector<int>>(cols, vector<int>(1 << litterCount, -1)));
        
        queue<vector<int>> q;
        q.push({startRow, startCol, 0, energy, 0}); 
        maxEnergy[startRow][startCol][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int mask = curr[2];
            int currEnergy = curr[3];
            int moves = curr[4];
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && classroom[nr][nc] != 'X') {
                    int nextEnergy = currEnergy - 1;
                    if (nextEnergy < 0) continue;
                    
                    int nextMask = mask;
                    if (classroom[nr][nc] == 'L') {
                        nextMask |= (1 << litterId[nr][nc]);
                    }
                    
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }
                    
                    if (nextMask == targetMask) {
                        return moves + 1;
                    }
                    
                    if (nextEnergy > maxEnergy[nr][nc][nextMask]) {
                        maxEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};