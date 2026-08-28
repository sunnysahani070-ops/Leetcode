// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int j=n;
        int ans=-1;
        while(i<=j){
            int k=i+(j-i)/2;
            if(isBadVersion(k)){
                j=k-1;
                ans=k;
            }else{
                i=k+1;
            }
        }
        return ans;
        
    }
};