class Solution {
    const int MOD = 1337;
    
    int powMod(int x, int n) {
        int res = 1;
        x %= MOD;
        for (int i = 0; i < n; i++) {
            res = (res * x) % MOD;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        
        int last_digit = b.back();
        b.pop_back();
        
        int part1 = powMod(superPow(a, b), 10);
        int part2 = powMod(a, last_digit);
        
        return (part1 * part2) % MOD;
    }
};