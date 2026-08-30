class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        
        sort(capacity.begin(), capacity.end());
        
        int fullBags = 0;
        for (int i = 0; i < n; ++i) {
            if (additionalRocks >= capacity[i]) {
                additionalRocks -= capacity[i];
                fullBags++;
            } else {
                break;
            }
        }
        
        return fullBags;
    }
};