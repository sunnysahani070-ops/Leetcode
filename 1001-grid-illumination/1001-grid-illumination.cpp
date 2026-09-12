class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rowCount, colCount, diag1Count, diag2Count;
        unordered_set<long long> activeLamps;
        
        for (const auto& lamp : lamps) {
            int r = lamp[0];
            int c = lamp[1];
            long long hash = (long long)r * n + c;
            
            if (activeLamps.insert(hash).second) {
                rowCount[r]++;
                colCount[c]++;
                diag1Count[r - c]++;
                diag2Count[r + c]++;
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        int dirs[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        
        for (const auto& q : queries) {
            int r = q[0];
            int c = q[1];
            
            if (rowCount[r] > 0 || colCount[c] > 0 || diag1Count[r - c] > 0 || diag2Count[r + c] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    long long hash = (long long)nr * n + nc;
                    if (activeLamps.erase(hash)) {
                        rowCount[nr]--;
                        colCount[nc]--;
                        diag1Count[nr - nc]--;
                        diag2Count[nr + nc]--;
                    }
                }
            }
        }
        
        return ans;
    }
};