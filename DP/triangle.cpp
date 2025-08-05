#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recursion(int r,int c,int m,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(r==m-1){
            return triangle[r][c];
        }
        if(r>=m || c>=n || r<0 || c<0) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        int down=recursion(r+1,c,m,n,triangle,dp);
        int right=recursion(r+1,c+1,m,n,triangle,dp);
        return dp[r][c]=triangle[r][c]+min(down,right);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        int c=triangle[r-1].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return recursion(0,0,r,c,triangle,dp);
    }
};