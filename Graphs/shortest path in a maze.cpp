class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>>distm(n,vector<int>(n,INT_MAX));
        distm[0][0]=1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<pair<int,int>>directions;
        directions={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
        while(!q.empty()){
            auto it=q.front();
            int dist=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            for(auto [dr,dc]:directions){
                int row=r+dr;
                int col=c+dc;
                if(row>=0 && row<n and col>=0 && col<n && grid[row][col]==0 && dist+1<distm[row][col] ){
                    distm[row][col]=dist+1;
                    if(row==n-1 && col==n-1) return distm[row][col];
                    q.push({distm[row][col],{row,col}});
                }
            }
        }
        return -1;
    }
};