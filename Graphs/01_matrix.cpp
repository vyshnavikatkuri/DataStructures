#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } 
                else{
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
           auto[r,c]=q.front().first;
           int distance=q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
            int row=r+dir[i].first;
            int col=c+dir[i].second;
            if(row>=0 && col>=0 && row<mat.size() && col<mat[0].size() && mat[row][col]==1 && vis[row][col]==0){
                dist[row][col]=distance+1;
                vis[row][col]=1;
                q.push({{row,col},dist[row][col]});
            }
           }
        }
        return dist;
    }
};
//multisource bfs
// You're given an m x n binary matrix mat of 0s and 1s.
// You need to return a matrix where each cell contains the distance to the nearest 0.

// 👉 Distance is measured in steps (up/down/left/right), where moving to an adjacent cell costs 1.

// 💡 Key Idea: Multi-Source BFS
// We are not finding distance from a single source, but from all 0s in the matrix to all 1s.

// This is why we use a multi-source BFS.

// 🔄 Why BFS?
// BFS gives the shortest path in an unweighted grid.

// If you do DFS or Dijkstra here, it'll be slower or unnecessary.

// Instead of starting from each 1 and searching for the nearest 0 (which is slow), we do the opposite:

// 👉 Start from all 0s at once, and spread out in layers to find the nearest 0 for each 1
//  Time Complexity: O(m × n)
// Operation	Time
// Loop over all cells (initialization)	O(m × n)
// Each cell is added to queue once	O(m × n)
// Each cell has 4 directions (constant)	O(1) per cell

// ✅ So total time:
// text
// Copy
// Edit
// O(m × n)
// Because each cell is visited at most once during BFS.

// ✅ Space Complexity: O(m × n)
// Component	Space	Description
// Queue (BFS)	O(m × n)	In worst case, all cells could be in the queue
// Grid itself	O(1)	Modified in-place
// No extra visited needed		Because you mark rotten cells in-place

// ✅ So total space:
// text
// Copy
// Edit
// O(m × n)