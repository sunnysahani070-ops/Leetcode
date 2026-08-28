class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefixPlates(n, 0);
        vector<int> leftCandle(n, -1);
        vector<int> rightCandle(n, -1);
        
        int platesCount = 0;
        int lastCandle = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                platesCount++;
            } else {
                lastCandle = i;
            }
            prefixPlates[i] = platesCount;
            leftCandle[i] = lastCandle;
        }
        
        lastCandle = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') {
                lastCandle = i;
            }
            rightCandle[i] = lastCandle;
        }
        
        vector<int> res;
        res.reserve(queries.size());
        for (const auto& q : queries) {
            int left = rightCandle[q[0]];
            int right = leftCandle[q[1]];
            
            if (left != -1 && right != -1 && left < right) {
                res.push_back(prefixPlates[right] - prefixPlates[left]);
            } else {
                res.push_back(0);
            }
        }
        
        return res;
    }
};