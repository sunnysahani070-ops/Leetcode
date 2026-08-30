class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        long long current_k = k;
        long long sum = (current_k * (current_k + 1)) / 2;
        
        for (int num : nums) {
            if (num <= current_k) {
                sum -= num;
                current_k++;
                sum += current_k;
            } else {
                break;
            }
        }
        
        return sum;
    }
};