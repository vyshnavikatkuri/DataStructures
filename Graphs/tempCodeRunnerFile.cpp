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
    cout<<r;
    return 0;
    
}
