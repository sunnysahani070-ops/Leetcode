class Solution {
private:
    string ans = "";
    
    bool build(int index, vector<int>& freq, const string& target) {
        if (index == target.size()) {
            return false; 
        }

        int c = target[index] - 'a';
        if (freq[c] > 0) {
            freq[c]--;
            ans += target[index];
            
            if (build(index + 1, freq, target)) {
                return true;
            }
            ans.pop_back();
            freq[c]++;
        }
        for (int i = c + 1; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                ans += (char)(i + 'a');
                for (int j = 0; j < 26; j++) {
                    while (freq[j] > 0) {
                        ans += (char)(j + 'a');
                        freq[j]--;
                    }
                }
                return true;
            }
        }
        
        return false;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        ans = "";
        
        if (build(0, freq, target)) {
            return ans;
        }
        
        return "";
    }
};