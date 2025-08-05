#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>temp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
            temp.push_back(node);
        }
        return temp; 
    }
};