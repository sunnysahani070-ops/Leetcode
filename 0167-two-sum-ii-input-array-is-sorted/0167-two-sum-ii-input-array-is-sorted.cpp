class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> a(2,-1);
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                a[0]=i+1;
                a[1]=j+1;
                break;
            }else if(numbers[i]+numbers[j]>target){
                j--;
            }else{
                i++;
            }
        }
        return a;
        
    }
};