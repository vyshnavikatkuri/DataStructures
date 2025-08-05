#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min+=1;
                max+=1;
            }else if(s[i]==')'){
                min-=1;
                max-=1;
            }else{
                min-=1;
                max+=1;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0);
    }
};
// ((**)) range:0,1,2,*(1,2,3),*(0,4)
// min=0,max=0;
// min=1,max=1
// min=2,max=2
// range range:1,2,3
// min=1,max=3