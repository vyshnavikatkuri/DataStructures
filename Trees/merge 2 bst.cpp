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
class Solution {
public: 
    void inorder(TreeNode* root,vector<int>&arr){
        if(root!=NULL){
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
    TreeNode* buildtree(vector<int>&temp,int st,int end){
        if(st>end) return NULL;
        int mid=st+(end-st)/2;
        TreeNode* root=new TreeNode(temp[mid]);
        root->left=buildtree(temp,st,mid-1);
        root->right=buildtree(temp,mid+1,end);
        return root;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        vector<int>arr1,arr2,temp;
        inorder(root1,arr1);
        inorder(root2,arr2);
        int i=0,j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        while(i<arr1.size()) temp.push_back(arr1[i++]);
        while(j<arr2.size()) temp.push_back(arr2[j++]);
        return buildtree(temp,0,temp.size()-1);
        
    }
    //use inorder to get 2 sorted arrays,then merge it to get one sorted array
    //now,build a tree using that sorted array by always taking mid ele as the root
};