#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int m,int n,vector<vector<int>>&vis){
        vis[r][c]=1;
        vector<int>dirr={1,0,-1,0};
        vector<int>dirc={0,1,0,-1};
        for(int i=0;i<4;i++){
            int row=r+dirr[i];
            int col=c+dirc[i];
            if(row>=0 && row<m && col>=0 && col<n && grid[row][col]=='1' &&
            !vis[row][col]){
                    dfs(grid,row,col,m,n,vis);
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size(),is=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,m,n,vis);
                    is++;
                }
            }
        }
         return is;
    }
};