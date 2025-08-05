#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void gStrings(string &b,vector<string>&ans,int n){
        if(b.size()==n){
            ans.push_back(b);
            return;
        }
        if(b.empty()||b.back()!='0' ){
            b.push_back('0');
            gStrings(b,ans,n);
            b.pop_back();
        }
        b.push_back('1');
        gStrings(b,ans,n);
        b.pop_back();
    }
    vector<string> validStrings(int n) {
        string b="";
        vector<string>ans;
        gStrings(b,ans,n);
        return ans;
    }
};