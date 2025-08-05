class Solution {
    public:
        void flatten(TreeNode* root) {
            if(root==NULL) return;
            flatten(root->left);
            flatten(root->right);
            if(root->left!=NULL){
                TreeNode* rightsubtree=root->right;
                root->right=root->left;
                root->left=NULL;
                TreeNode *current=root->right;
                while(current->right!=NULL){
                    current=current->right;
                }
                current->right=rightsubtree;
            }
        }
    };
    // Time Complexity (TC)
    // Flattening Left and Right Subtrees:
    
    // The flatten(root->left) and flatten(root->right) recursively traverse the entire tree.
    
    // Traversal to Find the Rightmost Node:
    
    // The while(current->right != NULL) loop can traverse up to the height of the tree in the worst case, which is O(N) for a skewed tree.
    
    // Overall Complexity:
    
    // The worst-case time complexity is O(N²) because for each node, it may take O(N) time to find the rightmost node.
    
    // Time Complexity: O(N²) in the worst case for a skewed tree.
    // Time Complexity: O(N) for a balanced tree, since the rightmost node search will be much faster.