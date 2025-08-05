#include<bits/stdc++.h>
using namespace std;
void dfsft(int curr,vector<vector<int>>&adj, vector<int>&vis,stack<int>&st){
    vis[curr]=1;
    for(int neigh:adj[curr]){
        if(!vis[neigh]){
            dfsft(neigh,adj,vis,st);
        }
    }
    st.push(curr);
}
void dfs(int curr,vector<vector<int>>&revadj, vector<int>&vis){
    vis[curr]=1;
    for(int neigh:revadj[curr]){
        if(!vis[neigh]){
            dfs(neigh,revadj,vis);
        }
    }
}
int scc(int V,vector<vector<int>>adj){
    //step 1 sort nodes in order of finishing time
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfsft(i,adj,vis,st);
        }
    }
    //step 2 reverse edges
    vector<vector<int>>revadj(V);
    for(int i=0;i<adj.size();i++){
         for(int neigh:adj[i]){
            revadj[neigh].push_back(i);
         }
    }
    //step 3 do dfs and find scc
    fill(vis.begin(),vis.end(),0);
    int cnt=0;
    while(!st.empty()){
        int top=st.top();
         st.pop();
        if(!vis[top]) {
            cnt++;
            dfs(top,revadj,vis);
        }
    }
    return cnt; 
}