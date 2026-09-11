class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        
        int ans = 0;
        for (int i = 100; i <= 998; i += 2) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
            
            count[a]--;
            count[b]--;
            count[c]--;
            
            if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0) {
                ans++;
            }
            
            count[a]++;
            count[b]++;
            count[c]++;
        }
        
        return ans;
    }
};