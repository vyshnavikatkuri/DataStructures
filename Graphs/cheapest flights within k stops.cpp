class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> >pq;
        pq.push({0,{src,0}});
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){
            int stops=pq.top().first;
            int node=pq.top().second.first;
            int price=pq.top().second.second;
            pq.pop();
            if(stops<=k){
                for(auto it:adj[node]){
                    int neighnode=it.first;
                    int neighprice=it.second;
                    if(neighprice+price<dist[neighnode]){
                        dist[neighnode]=price+neighprice;
                        pq.push({stops+1,{neighnode,price+neighprice}});
                    }
                }
            }
        }
            if(dist[dst]==INT_MAX) return -1;
            else return dist[dst];
        }
    };