class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       for(int i=0;i<times.size();i++){
        int u=times[i][0];
        int v=times[i][1];
        int wt=times[i][2];
        adj[u].push_back({v,wt});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>dist(n+1,INT_MAX);
       dist[k]=0;
       pq.push({dist[k],k});
       while(!pq.empty()){
        int time=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto [adjnode,edgwt]:adj[node]){
            if(time+edgwt<dist[adjnode]){
                dist[adjnode]=time+edgwt;
                pq.push({dist[adjnode],adjnode});
            }
        }
       }
        int mintime=INT_MIN;
       for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX){
            return -1;
        }
          mintime=max(mintime,dist[i]);
       }
       return mintime;


    }
};