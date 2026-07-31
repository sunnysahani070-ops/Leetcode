#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int memo[105][105];
    
    int solve(vector<int>& cuts, int i, int j) {
        
        if (i + 1 >= j) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int min_cost = 1e9;
        
        
        for (int k = i + 1; k < j; k++) {
            int cost = cuts[j] - cuts[i] + solve(cuts, i, k) + solve(cuts, k, j);
            min_cost = min(min_cost, cost);
        }
        
        return memo[i][j] = min_cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        
        
        sort(cuts.begin(), cuts.end());
        
        memset(memo, -1, sizeof(memo));
        
        
        return solve(cuts, 0, cuts.size() - 1);
    }
};