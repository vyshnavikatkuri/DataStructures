/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void getpaths(Node* root,vector<vector<int>>&ans,vector<int>&ds){
        if(root==NULL) return;
        ds.push_back(root->data);
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(ds);
        }else{
            getpaths(root->left,ans,ds);
            getpaths(root->right,ans,ds);
        }
        ds.pop_back();
       
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>ds;
        getpaths(root,ans,ds);
        return ans;
    }
};