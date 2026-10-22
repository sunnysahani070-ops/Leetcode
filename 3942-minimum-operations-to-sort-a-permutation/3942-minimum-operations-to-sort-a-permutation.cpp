#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int idx0 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx0 = i;
                break;
            }
        }

        bool inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx0 + i) % n] != i) {
                inc = false;
                break;
            }
        }

        if (inc) {
            return min(idx0, n - idx0 + 2);
        }

        bool dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx0 - i + n) % n] != i) {
                dec = false;
                break;
            }
        }

        if (dec) {
            return min(idx0 + 2, n - idx0);
        }

        return -1;
    }
};