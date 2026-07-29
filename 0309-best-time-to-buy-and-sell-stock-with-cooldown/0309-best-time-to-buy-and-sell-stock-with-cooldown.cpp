class Solution {
private:
    int solve(int day, bool buying, vector<int>& prices, vector<vector<int>>& memo) {
        if (day >= prices.size()) {
            return 0;
        }
        
        if (memo[day][buying] != -1) {
            return memo[day][buying];
        }
        
        if (buying) {
            int buyOption = -prices[day] + solve(day + 1, false, prices, memo);
            int skipOption = solve(day + 1, true, prices, memo);
            
            return memo[day][buying] = max(buyOption, skipOption);
        } else {
            int sellOption = prices[day] + solve(day + 2, true, prices, memo);
            int skipOption = solve(day + 1, false, prices, memo);
            
            return memo[day][buying] = max(sellOption, skipOption);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return solve(0, true, prices, memo);
    }
};