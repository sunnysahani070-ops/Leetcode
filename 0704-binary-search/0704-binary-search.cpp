class Solution {
    int bs(vector<int>& arr, int n, int t) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == t) {
                return mid;
            } else if (arr[mid] > t) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int f = nums.size();
        return bs(nums, f, target);
    }
};