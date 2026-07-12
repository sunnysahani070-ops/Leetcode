class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0 || hand.size() < groupSize) {
            return false;
        }
        map<int, int> mpp;
        for (int i = 0; i < hand.size(); i++) {
            mpp[hand[i]]++;
        }
        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            if (it->second > 0) {
                int val = it->second;
                for (auto it = mpp.begin(); it != mpp.end(); ++it) {
                    if (it->second > 0) {
                        int val = it->second;

                        
                        for (int i = 1; i < groupSize; i++) {
                            if (mpp[it->first + i] < val) {
                                return false;
                            }
                            mpp[it->first + i] -=
                                val; // Correct map access syntax
                        }

                        // 2. Decrement the starting card once after the loop
                        it->second = 0;
                    }
                }
            }
        }
        return true;
    }
};