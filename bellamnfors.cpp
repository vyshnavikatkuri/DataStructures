#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                // Negative cycle detected
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> res = obj.bellman_ford(V, edges, src);

    if (res.size() == 1 && res[0] == -1) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        for (int d : res) {
            if (d == INT_MAX) cout << "INF ";
            else cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
