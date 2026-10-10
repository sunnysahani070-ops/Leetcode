class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long totalK = k1 + k2;
        long long sumSq = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sumSq += diff[i] * diff[i];
        }

        long long totalDiff = 0;
        for (long long d : diff) {
            totalDiff += d;
        }

        if (totalDiff <= totalK) {
            return 0;
        }

        map<long long, long long, greater<long long>> counts;
        for (long long d : diff) {
            counts[d]++;
        }

        long long remK = totalK;
        while (remK > 0 && !counts.empty()) {
            auto it = counts.begin();
            long long val = it->first;
            long long count = it->second;
            counts.erase(it);

            auto nextIt = counts.begin();
            long long nextVal = counts.empty() ? 0 : nextIt->first;
            
            long long diffVal = val - nextVal;
            long long totalCanReduce = diffVal * count;

            if (remK >= totalCanReduce) {
                remK -= totalCanReduce;
                if (!counts.empty()) {
                    nextIt->second += count;
                }
            } else {
                long long reduceEach = remK / count;
                long long remainder = remK % count;

                long long newVal = val - reduceEach;
                counts[newVal] += (count - remainder);
                if (remainder > 0) {
                    counts[newVal - 1] += remainder;
                }
                remK = 0;
            }
        }

        long long ans = 0;
        for (auto& p : counts) {
            ans += p.first * p.first * p.second;
        }

        return ans;
    }
};