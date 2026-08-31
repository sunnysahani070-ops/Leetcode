class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int b = 1;
        int a_len_sum = 0;
        int msg_len = message.length();
        
        // Step 1: Find the minimum total number of parts (b)
        while (true) {
            int b_len = to_string(b).length();
            a_len_sum += b_len; // The length of 'a' for the current part
            
            // Total characters taken by all suffixes if we split into 'b' parts
            int total_suffix_len = 3 * b + b * b_len + a_len_sum;
            
            // Total characters available for the actual message
            int capacity = b * limit - total_suffix_len;
            
            // If the suffix "<b/b>" alone is equal to or larger than the limit,
            // we can't fit any message characters. It's impossible.
            if (3 + 2 * b_len >= limit) {
                return {};
            }
            
            // If we have enough capacity to hold the entire message, we found our 'b'
            if (capacity >= msg_len) {
                break;
            }
            
            b++;
        }
        
        // Step 2: Construct the resulting strings
        vector<string> result;
        int curr_idx = 0;
        
        for (int a = 1; a <= b; ++a) {
            string suffix = "<" + to_string(a) + "/" + to_string(b) + ">";
            int chars_to_take = limit - suffix.length();
            
            string part = message.substr(curr_idx, chars_to_take);
            result.push_back(part + suffix);
            
            curr_idx += chars_to_take;
        }
        
        return result;
    }
};