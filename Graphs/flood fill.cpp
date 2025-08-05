#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num=image[sr][sc];
        if(num==color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto [dr,dc]:dir){
                int row=r+dr;
                int col=c+dc;
                if(row>=0 && col>=0 && row<image.size() && col<image[0].size() && image[row][col]==num){
                    image[row][col]=color;
                    q.push({row,col});
                }
            }
        }
        return image;
    }
};