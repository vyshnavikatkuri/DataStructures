#include<bits/stdc++.h>
using namespace std;
int MST(int V,vector<vector<int>>adj){
    vector<vector<pair<int,int>>>graph(V);
    for(auto edge:adj){
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<int>vis(V,0);
    int mincost=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        if(vis[node]==0){
            vis[node]=1;
            mincost+=wt;
            for(auto neighbour:graph[node]){
                int edgwt=neighbour.second;
                int neigh=neighbour.first;
                if(!vis[neigh]){
                    pq.push({edgwt,neigh});
                }
            }
        }
    }
    return mincost;
}
int main(){
    int r=MST(3,{{0,1,5},{1,2,3},{0,2,1}});
    cout<<r<<endl;
    return 0;
    
}
// Prim's Minimum Spanning Tree Algorithm:
// This is also a greedy algorithm. This algorithm has the following workflow:

// It starts by selecting an arbitrary vertex and then adding it to the MST. 
// Then, it repeatedly checks for the minimum edge weight that connects one vertex of MST to another vertex that is not yet in the MST. 
// This process is continued until all the vertices are included in the MST. 