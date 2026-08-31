class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="abc";
        int digit=-1;
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] &&num[i]==num[i+2]){
                if(digit==-1 || digit<(num[i]-'0')){
                    digit=num[i]-'0';
                    ans[0]=num[i];
                    ans[1]=num[i];
                    ans[2]=num[i];

                }
            }

        }
        if(digit==-1){
            return "";
        }
        return ans;
        
    }
};