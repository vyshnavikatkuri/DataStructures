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
int diameter(TreeNode* root,int dia){
    if(root==NULL) return 0;
    int lh=diameter(root->left,dia);
    int rh=diameter(root->right,dia);
    int localdia=lh+rh;
    dia=max(dia,localdia);
    return 1+max(lh+rh);
}
int dtree(TreeNode* root){
    if(root==NULL) return 0;
    int dia=0;
    int d=(root,dia);
    return d;
}