#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int curr,int col,vector<vector<int>>& graph,vector<int>&color){
        color[curr]=col;
        for(int ele:graph[curr]){
            if(color[ele]==-1){
                if(!dfs(ele,!col,graph,color)) return false;
            }else if(color[ele]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph,color)) return false;
            }
        }
        return true;

    }
};