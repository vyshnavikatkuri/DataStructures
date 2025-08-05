/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{//both left and right are not null means we found the root
            return root;
        }

    }
};
// Time Complexity: O(n)
// Why?
// The function visits every node once in the worst case to find p and q.

// n = total number of nodes in the tree.

// Even if p and q are deep in the tree or on opposite sides, you must traverse the tree entirely to be sure of their positions.

// 🧠 Space Complexity: O(h)
// h = height of the tree

// Comes from the recursive call stack during traversal.