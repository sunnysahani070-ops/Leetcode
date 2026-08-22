class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int a=0;
        int b=1;

        for(int i=0;i<s.size();i++){
            a+=s[i]-'0';
            b*=s[i]-'0';

        }
        int k=a+b;
        if(n%k==0){
            return true;
        }
        return false;
        
        
    }
};