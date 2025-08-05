#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>vis(adj.size(),0);
        queue<int>q;
        q.push(0);
        vector<int>v;
        vis[0]=1;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            v.push_back(ele);
            for(int i:adj[ele]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
            }
        }
        }
        return v;
        
    }
};
//time complexity:o(V+E)
//sc:o(V)
// Time Complexity of BFS
// The time complexity of Breadth-First Search (BFS) on a graph is:

// scss
// Copy
// Edit
// O(V + E)
// Where:

// V = number of vertices (nodes)

// E = number of edges

// 🔍 Explanation:
// Each node is visited once:

// When it is dequeued from the queue and added to the result.

// So total node visits = V

// Each edge is considered once:

// For an undirected graph, each edge (u, v) is present in both adj[u] and adj[v]

// But since we only enqueue unvisited nodes, every edge leads to at most 2 explorations (one from each end).

// So total edge explorations = 2E → counted as O(E)

// 🧠 Final Complexity:
// Case	Time Complexity
// Undirected Graph	O(V + E)
// Directed Graph	O(V + E)

// ✅ Space Complexity:
// scss
// Copy
// Edit
// O(V)
// visited[] array → size V

// queue → can hold up to V nodes in worst case

// result vector → size V