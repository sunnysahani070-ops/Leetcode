class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count the frequency of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Step 2: Find the maximum frequency
        int max_freq = 0;
        for (int f : freq) {
            max_freq = max(max_freq, f);
        }
        
        // Step 3: Count how many tasks share this maximum frequency
        int count_max = 0;
        for (int f : freq) {
            if (f == max_freq) {
                count_max++;
            }
        }
        
        // Step 4: Calculate the minimum slots needed based on the formula
        int ans = (max_freq - 1) * (n + 1) + count_max;
        
        // Step 5: Return the larger value between the formula and total tasks
        return max(ans, (int)tasks.size());
    }
};