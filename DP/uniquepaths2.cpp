#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int r,int c,int m,int n,vector<pair<int,int>>&dir,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int paths=0;
        for(auto &[dr,dc]:dir){
            int i=r+dr;
            int j=c+dc;
            if(i<m && j<n && i>=0 && j>=0 && obstacleGrid[i][j]==0){
                paths+=dfs(i,j,m,n,dir,obstacleGrid,dp);
            }
        }
        return dp[r][c]=paths;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]||obstacleGrid[0][0]) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<pair<int,int>>dir={{0,1},{1,0}};
        return dfs(0,0,m,n,dir,obstacleGrid,dp);
    }
};