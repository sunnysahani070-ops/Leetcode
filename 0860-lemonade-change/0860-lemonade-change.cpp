class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int store[3]={0};
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                store[0]+=1;
            }else if(bills[i]==10){
                if(store[0]>0){
                    store[0]--;
                    store[1]++;
                }else{
                    return false;
                }
            }else{
                if(store[0]>0 && store[1]>0){
                    store[0]--;
                    store[1]--;
                    store[2]++;
                }else if(store[0]>=3 ){
                    store[0]-=3;
                    store[2]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;

        
    }
};