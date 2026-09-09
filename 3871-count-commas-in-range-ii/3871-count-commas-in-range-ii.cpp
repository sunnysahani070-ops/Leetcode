class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long limit = 1000;
        while (n >= limit) {
            commas += (n - limit + 1);
            limit *= 1000;
        }
        return commas;
    }
};