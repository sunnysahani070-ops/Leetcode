class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx = 0;
        int i = 0;
        int n = s.length(); 
        map<char, int> mpp;
        
        for (int j = 0; j < n; j++) {
            mpp[s[j]]++;
            while (mpp[s[j]] > 2) {
                mpp[s[i]]--; 
                i++; 
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};