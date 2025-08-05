
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(root==NULL)
                return ans;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int s=q.size();
                vector<int>v;
                for(int i=0;i<s;i++){
                    TreeNode*node=q.front();
                    q.pop();
                    if(node->left!=NULL)
                        q.push(node->left);
                    if(node->right!=NULL)
                        q.push(node->right);
                    v.push_back(node->val);
                }
                ans.push_back(v);
            }
            return ans;
        }
    };
    // Complexity Analysis

    // Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.
    
    // Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.