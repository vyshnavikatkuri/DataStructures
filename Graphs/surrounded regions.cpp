#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findway(int row,int col,vector<vector<char>>& board){
        if(row<board.size() && col<board[0].size() && row>=0 && col>=0 && board[row][col]=='O'){
            board[row][col]='#';
            findway(row+1,col,board);
            findway(row-1,col,board);
            findway(row,col+1,board);
            findway(row,col-1,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                findway(i,0,board);
            }
            if(board[i][n-1]=='O'){
                findway(i,n-1,board);
            }
        }
         for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                findway(0,i,board);
            }
            if(board[m-1][i]=='O'){
                findway(m-1,i,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
      

    }
};