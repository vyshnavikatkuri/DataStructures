#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void gParenthesis(string &p,int leftp,int rightp,int n,vector<string>&ans){
        if(leftp==rightp && leftp+rightp==n*2){
            ans.push_back(p);
            return;
        }
        if(leftp<n){
            p.push_back('(');
            gParenthesis(p,leftp+1,rightp,n,ans);
            p.pop_back();
        }
        if(rightp<leftp){
            p.push_back(')');
            gParenthesis(p,leftp,rightp+1,n,ans);
            p.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string p="";
        vector<string>ans;
        gParenthesis(p,0,0,n,ans);
        return ans;
    }
};
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 