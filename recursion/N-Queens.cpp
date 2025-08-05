class Solution {
public:
    void placeQ(int ind,vector<string>&board,vector<vector<string>>&ans,int n){
        if(ind==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,i,ind)){
                board[i][ind]='Q';
                placeQ(ind+1,board,ans,n);
                board[i][ind]='.';
            }
        }
    }
    bool isSafe(vector<string>&board,int row,int col){
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int j=col;j>=0;j--){
            if(board[row][j]=='Q') return false;
        }
        for(int i=row+1,j=col-1;i<board.size()&&j>=0;i++,j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
           board[i]=s;
        }
        placeQ(0,board,ans,n);
        return ans;
    }
};