#include <vector>

class Solution {
public:
    int uniquePaths(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1'000'000'007;

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = 1;

        auto getNext = [&](int r, int c, int dir) -> std::pair<int, int> {
            while (true) {
                if (r == m - 1 && c == n - 1) {
                    return {r, c};
                }
                if (grid[r][c] == 0) {
                    return {r, c};
                }
                if (dir == 0) {
                    r++;
                    dir = 1;
                } else {
                    c++;
                    dir = 0;
                }
                if (r >= m || c >= n) {
                    return {-1, -1};
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                if (j + 1 < n) {
                    auto [ni, nj] = getNext(i, j + 1, 0);
                    if (ni != -1 && nj != -1) {
                        dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                    }
                }

                if (i + 1 < m) {
                    auto [ni, nj] = getNext(i + 1, j, 1);
                    if (ni != -1 && nj != -1) {
                        dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};