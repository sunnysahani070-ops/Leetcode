class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        vector<vector<int>> count(2 * n + 1, vector<int>(2 * n + 1, 0));
        int maxOverlap = 0;
        
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                int shift_r = p2.first - p1.first + n;
                int shift_c = p2.second - p1.second + n;
                
                count[shift_r][shift_c]++;
                maxOverlap = max(maxOverlap, count[shift_r][shift_c]);
            }
        }
        
        return maxOverlap;
    }
};