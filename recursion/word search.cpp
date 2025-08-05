#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool isExisting(int row,int col,int m,int n,vector<vector<char>>& board,int ind,string word){
        return (row>=0 && col>=0 && row<m && col<n && board[row][col]==word[ind]);
    }
    bool search(int r,int c,int m,int n,vector<vector<char>>& board,string word,int ind){
        if(ind==word.size()) return true;
        char temp=board[r][c];
        board[r][c]='0';
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(isExisting(newr,newc,m,n,board,ind,word)){
                if(search(newr,newc,m,n,board,word,ind+1)) return true;
            }  
        }
        board[r][c]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(i, j, m, n, board, word, 1)) return true;
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(m × n × 4^L)
// Where:
// m = number of rows in the board

// n = number of columns

// L = length of the word

// 🔍 Why?
// You check every cell on the board as a starting point → O(m × n)

// From each cell, you explore 4 directions (up, down, left, right) recursively.

// In the worst case, at each step of the word (length = L), you explore up to 4 choices → O(4^L)

// So total worst-case complexity:

// scss
// Copy
// Edit
// O(m × n × 4^L)
// 🧠 Space Complexity: O(L)
// Why?
// The only extra space used is the recursion stack for DFS.

// In the worst case, the depth of recursion is L (length of the word).

// You are modifying the board in-place, so no additional visited matrix is used.