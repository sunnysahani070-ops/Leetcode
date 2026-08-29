class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getMaxLen(answerKey, k, 'T'), getMaxLen(answerKey, k, 'F'));
    }

private:
    int getMaxLen(string& s, int k, char target) {
        int left = 0;
        int max_len = 0;
        int flips = 0;
        
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != target) {
                flips++;
            }
            while (flips > k) {
                if (s[left] != target) {
                    flips--;
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};