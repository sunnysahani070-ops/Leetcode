#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // BFS queue stores {row, col, path_length}
        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1; // Mark as visited by setting to 1

        // 8 possible directions
        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int dist = curr[2];

            // Reached the destination
            if (r == n - 1 && c == n - 1) {
                return dist;
            }

            // Explore neighbors
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark visited
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        return -1;
    }
};