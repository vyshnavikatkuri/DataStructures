#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& vis, int par) {
        vis[curr] = 1;
        for (int neigh : adj[curr]) {
            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, curr)) return true;
            } 
            else if (neigh != par) return true;
        }
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, -1)) return true;
            }
        }
        return false;
    }
};  // ✅ Final closing brace for the class
// Part	Complexity	Explanation
// Building adjacency list	O(E)	Each edge is added twice (once for each direction)
// DFS traversal	O(V + E)	Each node is visited once, and all edges are explored

// V = number of vertices (nodes)

// E = number of edges

// ✅ Space Complexity: O(V + E)
// Component	Space	Reason
// Adjacency list	O(V + E)	To store the undirected graph
// Visited array vis	O(V)	To track visited nodes
// Recursion stack	O(V)	In worst case (like a long chain), DFS can go as deep as all V nodes

// So overall:

// text
// Copy
// Edit
// Time  = O(V + E)
// Space = O(V + E)