class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        long long MOD = 1e9 + 7;
        long long num = 1, den = 1;
        
        for (int i = 1; i <= k; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * i) % MOD;
        }
        
        long long waysToChooseK = (num * power(den, MOD - 2)) % MOD;
        long long waysForRest = power(m - 1, n - 1 - k);
        
        long long ans = (waysToChooseK * waysForRest) % MOD;
        return (ans * m) % MOD;
    }
};