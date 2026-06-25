class Solution {
    int nCr(int n, int r) {
            int res = 1;

            for (int i = 0; i < r; i++) {
                res = res * (n - i);
                res = res / (i + 1);
            }

            return res;
        }
public:
    vector<vector<int>> generate(int numRows) {
        
        
        vector<vector<int>> w;
        for (int i = 0; i < numRows; i++) {
            vector<int> a;
            for(int j = 0; j <= i; j++) {
                
                int q = nCr(i, j);
                a.push_back(q);
            };
            w.push_back(a);
            
        };
        return w;
    }
};