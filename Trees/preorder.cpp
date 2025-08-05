
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
 public:
    void preorder(TreeNode*root,vector<int>&arr){
        if(root==NULL) return;
        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>arr;
        preorder(root,arr);
        return arr;
    }
};


//tc:o(n),sc:o(n)
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.