class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int p = -1;
        int q = -1;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] > mx){
                mx = nums[i];
                p = i;
            }
            if(nums[i] < mn){
                mn = nums[i];
                q = i;
            }
        }
        
        int left = min(p, q);
        int right = max(p, q);
        
        int both_front = right + 1;
        
        int both_back = n - left;
        
        int front_and_back = (left + 1) + (n - right);
        
        int ans = min({both_front, both_back, front_and_back});
        
        return ans;
    }
};