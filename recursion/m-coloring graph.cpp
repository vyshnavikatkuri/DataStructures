//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool issafe(int node,int v,vector<vector<int>>& graph,int color[],int col){
        for(int i=0;i<v;i++){
            if(graph[node][i]&&color[i]==col) return false;
        }
        return true;
    }
    bool solve(int node,int v,vector<vector<int>>& graph, int m,int color[]){
        if(node==v) return true;
        for(int col=1;col<=m;col++){
            if(issafe(node,v,graph,color,col)) {
                color[node]=col;
                if(solve(node+1,v,graph,m,color)) return true;
                color[node]=0;
        }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for(int i=0;i<edges.size();i++){
            graph[edges[i].first][edges[i].second]=1;
            graph[edges[i].second][edges[i].first]=1;
        }
        int color[v]={0};
        return solve(0,v,graph,m,color);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends
// Worst-case: O(M^N) (try M colors for each of N vertices).

// Backtracking prunes the tree heavily in practice.