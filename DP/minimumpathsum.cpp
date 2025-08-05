#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recursion(int r,int c,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r==m-1 && c==n-1){
            return grid[r][c];
        }
        if(r<0 || c<0 ||r>=m ||c>=n) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        int right=recursion(r,c+1,m,n,grid,dp);
        int down=recursion(r+1,c,m,n,grid,dp);
        return dp[r][c]=grid[r][c]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recursion(0,0,m,n,grid,dp);
    }
};