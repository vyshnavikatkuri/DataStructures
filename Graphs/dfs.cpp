#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int curr,vector<vector<int>>& adj,vector<int>&vis,vector<int>&v){
        vis[curr]=1;
        v.push_back(curr);
        for(int ele:adj[curr]){
            if(!vis[ele]){
                dfs(ele,adj,vis,v);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>v;
        vector<int>vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis,v);
            }
        }
        return v;
    }
};