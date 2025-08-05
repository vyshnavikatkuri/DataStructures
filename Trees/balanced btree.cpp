// class Solution {
//     public:
//         int heights(TreeNode* root,bool &ans){
//             if(root==NULL) return 0;
//             int lefth=heights(root->left,ans);
//             int righth=heights(root->right,ans);
//             if(abs(lefth-righth)>1){
//               ans=false;
//             }
//             return lefth>righth?lefth+1:righth+1;
//         }
//         bool isBalanced(TreeNode* root) {
//             if(root==NULL) return true;
//             bool ans=true;
//             int l=heights(root,ans);
//             if(ans) return true;
//             else return false;
//         }
//     };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int heights(TreeNode* root){
        if(root==NULL) return 0;
        int lefth=heights(root->left);
        if(lefth==-1) return -1;
        int righth=heights(root->right);
        if(righth==-1) return -1;
        if(abs(lefth-righth)>1){
          return -1;
        }
        return max(lefth,righth)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return heights(root)!=-1;
    }
};