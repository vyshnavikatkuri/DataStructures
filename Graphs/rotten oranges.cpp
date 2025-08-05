#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cntf=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) cntf++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        int min=0;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty() && cntf>0){
            int size=q.size();
            min++;
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                   int row=r+dir[j][0];
                   int col=c+dir[j][1];
                   if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1){
                        grid[row][col]=2;
                        q.push({row,col});
                        cntf--;
                   }
                }
            }
        }
        return cntf==0?min:-1;
    }
};