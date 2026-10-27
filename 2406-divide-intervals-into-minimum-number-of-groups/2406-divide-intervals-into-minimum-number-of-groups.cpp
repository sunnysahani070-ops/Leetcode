class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }
        
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());
        
        int groups = 0, end_ptr = 0;
        for (int start : start_times) {
            if (start > end_times[end_ptr]) {
                end_ptr++;
            } else {
                groups++;
            }
        }
        
        return groups;
    }
};