//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* node=p.first;
            int ver=p.second;
            if(mp.find(ver)==mp.end()){
                mp[ver]=node->data;
            }
            if(node->left!=NULL) q.push({node->left,ver-1});
            if(node->right!=NULL) q.push({node->right,ver+1});
        }
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node* root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
// root[] = [1, 2, 3] 
 
// Output: [2, 1, 3]
// Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
// Output: [40, 20, 10, 30, 100]
// Explaination: The root 10 is visible.
// On the left, 40 is the leftmost node and visible, followed by 20.
// On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
// Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
//        1
//      /   \
//     2     3
//      \   
//       4
//        \
//         5
//          \
//           6
// Output: [2, 1, 3, 6]
// Explaination: Node 1 is the root and visible.
// Node 2 is the left child and visible from the left side.
// Node 3 is the right child and visible from the right side.
// Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.raversal using BFS (Breadth-First Search):

// Every node is processed once using a queue → O(N)

// Map Operations:

// Each insertion or lookup in the map (mp) is O(log V) using a balanced tree (Red-Black Tree).

// In the worst case, the number of unique verticals (V) is proportional to N → O(log N)

// Final Map Traversal to Form the Result:

// The map is traversed once to form the output → O(V), where V ≤ N.

// 📌 Total Time Complexity
// 𝑂
// (
// 𝑁
// log
// ⁡
// 𝑁
// )
// O(NlogN)
// Where:

// N → Number of nodes

// log N → Map insertion and lookup

// 📌 Space Complexity
// Map (mp) → Stores one node value per unique vertical. In the worst case, we may have N verticals → O(N)

// Queue (q) → In the worst case, it can store N nodes → O(N)

// Output (ans) → Stores at most N nodes → O(N)

// 📌 Total Space Complexity
// 𝑂
// (
// 𝑁
// )
// O(N)
// ✅ Final Complexity Summary
// Time Complexity: 
// 𝑂
// (
// 𝑁
// log
// ⁡
// 𝑁
// )
// O(NlogN)

// Space Complexity: 
// 𝑂
// (
// 𝑁
// )
// O(N)