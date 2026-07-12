class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Step 1: Initialize a boolean vector with 'true'
        vector<bool> isPrime(n, true);
        
        // Step 2: Sieve logic
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark multiples starting from i * i
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Step 3: Count how many 'true' values remain from index 2 to n-1
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};