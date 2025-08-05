#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(int ind,string s,vector<string>&ds,vector<vector<string>>&res){
        if(ind==s.size()){
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                backtrack(i+1,s,ds,res);
                ds.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int left,int right){
            while(left<=right){
                if(s[left]!=s[right]) return false;
                left++;
                right--;
            }
            return true;
    }
vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        backtrack(0,s,ds,res);
        return res;
    }
};