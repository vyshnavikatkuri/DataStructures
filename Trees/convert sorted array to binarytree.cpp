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
    TreeNode* buildTree(vector<int>& nums,int start,int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=buildTree(nums,start,mid-1);
        root->right=buildTree(nums,mid+1,end);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};
//sorted array of bst means,inorder traversal of bst
//inorder means left root right
//so,every time u find mid make it as root,root->left=left ele of mid and root->right=right ele of mid
// Visual Intuition:
// Level 0: 1 node (root)

// Level 1: 2 nodes

// Level 2: 4 nodes

// Level 3: 8 nodes

// ...

// Level h: up to 2^h nodes at that level

// The total number of nodes in such a full (or near-full) tree is:

// scss
// Copy
// Edit
// 1 + 2 + 4 + 8 + ... + 2^h ≈ 2^(h+1) - 1
// Let’s say total nodes = n, then:

// scss
// Copy
// Edit
// n ≈ 2^(h+1)
// Take log base 2:
// log2(n) ≈ h + 1
// => h ≈ log2(n) - 1
// So, the height h is O(log n).