class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0;
        int ones = 0;
        string ans = "";
        
        while (j < s.size()) {
            if (s[j] == '1') {
                ones++;
            }
            
            while (ones == k) {
                string current_str = s.substr(i, j - i + 1);
                
                if (ans == "" || current_str.length() < ans.length() || 
                   (current_str.length() == ans.length() && current_str < ans)) {
                    ans = current_str;
                }
                
                if (s[i] == '1') {
                    ones--; 
                }
                i++;
            }
            j++;
        }
        
        return ans;
    }
};