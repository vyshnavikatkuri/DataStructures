#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int curr,vector<vector<int>>&adj, vector<int>&vis, vector<int>&st){
        vis[curr]=1;
        st[curr]=1;
        for(int ele:adj[curr]){
            if(!vis[ele]){
                 if(dfs(ele,adj,vis,st)) return true;
            }
            else if(st[ele]) return true;
        }
        st[curr]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>st(V,0);
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,st)) return true;
            }
        }
        return false;
    }
};