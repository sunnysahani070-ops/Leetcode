class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long count = 0;
        for (long long i = 0; i * cost1 <= total; ++i) {
            long long remaining = total - i * cost1;
            count += (remaining / cost2) + 1;
        }
        return count;
    }
};