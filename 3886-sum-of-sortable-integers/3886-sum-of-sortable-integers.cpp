class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> drops;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                drops.push_back(i);
            }
        }
        
        int total_sum = 0;
        
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool possible = true;
            for (int idx : drops) {
                if (idx / k != (idx + 1) / k) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            
            for (int i = 0; i < n; i += k) {
                int drop_count = 0;
                int drop_pos = -1;
                for (int j = 0; j < k - 1; ++j) {
                    if (nums[i + j] > nums[i + j + 1]) {
                        drop_count++;
                        drop_pos = j;
                    }
                }
                
                if (drop_count > 1) {
                    possible = false;
                    break;
                }
                if (drop_count == 1 && nums[i + k - 1] > nums[i]) {
                    possible = false;
                    break;
                }
                
                int mn = (drop_count == 0) ? nums[i] : nums[i + drop_pos + 1];
                int mx = (drop_count == 0) ? nums[i + k - 1] : nums[i + drop_pos];
                
                if (mn != sorted_nums[i] || mx != sorted_nums[i + k - 1]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};