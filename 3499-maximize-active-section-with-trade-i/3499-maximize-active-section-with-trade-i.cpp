class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        string t = "1" + s + "1";
        
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        int max_gain = 0;
        int i = 0;
        
        while (i < t.length()) {
            if (t[i] == '1') {
                int j = i;
                while (j < t.length() && t[j] == '1') {
                    j++;
                }
                // Check if this '1'-segment is surrounded by '0'-segments (i.e., not at the very ends of t)
                if (i > 0 && j < t.length()) {
                    int prev_zero_start = i - 1;
                    while (prev_zero_start >= 0 && t[prev_zero_start] == '0') {
                        prev_zero_start--;
                    }
                    int zeros_left = (i - 1) - prev_zero_start;
                    
                    int next_zero_end = j;
                    while (next_zero_end < t.length() && t[next_zero_end] == '0') {
                        next_zero_end++;
                    }
                    int zeros_right = next_zero_end - j;
                    
                    int current_ones_len = j - i;
                    int contiguous_zeros = zeros_left + current_ones_len + zeros_right;
                    max_gain = max(max_gain, contiguous_zeros - current_ones_len);
                }
                i = j;
            } else {
                i++;
            }
        }
        
        return total_ones + max_gain;
    }
};