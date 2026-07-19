#include <vector>
using namespace std;

class Solution {
    
    int memo[101][101];

    int solve(int r, int c, int m, int n) {
        
        if (r == m - 1 && c == n - 1) return 1;
        
        if (r >= m || c >= n) return 0;
        
        
        if (memo[r][c] != -1) return memo[r][c];
        
        
        return memo[r][c] = solve(r + 1, c, m, n) + solve(r, c + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
    
        for(int i = 0; i < 101; ++i)
            for(int j = 0; j < 101; ++j)
                memo[i][j] = -1;
                
        return solve(0, 0, m, n);
    }
};