#include<bits/stdc++.h>
#include<stack>
using namespace std;
#include<string.h>
class Solution {
    public:
        bool isValid(string s) {
            stack<char>stack;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('||s[i]=='{'||s[i]=='['){
                    stack.push(s[i]);
                }else {
                    if(stack.empty()) return false;
                    else{   
                        if((s[i]==')'&&stack.top()=='(')||(s[i]=='}'&&stack.top()=='{')
                        ||(s[i]==']'&&stack.top()=='[')){
                            stack.pop();
                        }else{
                            return false;
                        }
                    }
                }
            }
            return stack.empty();
        }
    };