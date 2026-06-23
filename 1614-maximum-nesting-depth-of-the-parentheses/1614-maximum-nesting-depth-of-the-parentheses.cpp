#include <algorithm>
class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int depth=0;
        for(char ch:s ){
            if(ch=='('){
                depth++;
                maxdepth=max(depth,maxdepth);
                };
            if(ch==')'){
                depth--;
            };

        };
        return maxdepth;
        
    };
};