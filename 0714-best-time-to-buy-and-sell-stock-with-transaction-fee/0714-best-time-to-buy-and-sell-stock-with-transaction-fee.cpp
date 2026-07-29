class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        
        long long hold = -prices[0]; 
        long long cash = 0;          

        for (int i = 1; i < n; ++i) {
            
            hold = max(hold, cash - prices[i]);
            
            
            cash = max(cash, hold + prices[i] - fee);
        }

        return cash;
    }
};