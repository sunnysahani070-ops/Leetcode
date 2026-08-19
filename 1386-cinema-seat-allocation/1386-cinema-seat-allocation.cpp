#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowToMask;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            if (col >= 2 && col <= 9) {
                
                rowToMask[row] |= (1 << (col - 2));
            }
        }
        int maxFamilies = (n - rowToMask.size()) * 2;
        
        for (auto const& [row, mask] : rowToMask) {
            bool leftFree = (mask & 15) == 0;
            bool rightFree = (mask & 240) == 0; 
            bool middleFree = (mask & 60) == 0;
            
            if (leftFree && rightFree) {
                maxFamilies += 2;
            } else if (leftFree || rightFree || middleFree) {
                maxFamilies += 1;
            }
        }
        
        return maxFamilies;
    }
};