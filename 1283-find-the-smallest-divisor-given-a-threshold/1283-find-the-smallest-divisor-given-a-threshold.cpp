class Solution {
    int divsum(vector<int>& arr, int m) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] + m - 1) / m;
    };
    return sum;
};
    int maxel(vector<int> arr){
        int max=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=max){
                max=arr[i];
            };
        };return max;
    };
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=0;
        int low=1;
        int high=maxel(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(divsum(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            };
        };
        return ans;
        
    };
};