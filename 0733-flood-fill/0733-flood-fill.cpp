#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        
        // Guard Clause: If the starting pixel already has the target color, 
        // no changes are needed. This prevents infinite loops.
        if (iniColor == color) return image;
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color; // Change the color immediately when pushing
        
        // Direction vectors for moving Up, Right, Down, Left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // 1. Check boundary conditions
                // 2. Check if the neighbor has the original starting color
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    image[nrow][ncol] == iniColor) {
                    
                    image[nrow][ncol] = color; // Update color
                    q.push({nrow, ncol});
                }
            }
        }
        
        return image;
    }
};