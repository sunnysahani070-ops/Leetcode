class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> num1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){

            }else{num1.push_back(nums[i]);

            };
        }
        int m=num1.size();
        int a=n-m;
        for(int i=0;i<a;i++){
            num1.push_back(0);
        };
        nums=num1;


        
    }
};