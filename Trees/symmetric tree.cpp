class Solution {
    public:
        bool Symmetry(TreeNode* Tree1,TreeNode* Tree2){
            if(Tree1==NULL&&Tree2==NULL) return true;
            if(Tree1==NULL||Tree2==NULL) return false;
            if(Tree1->val==Tree2->val){
                return Symmetry(Tree1->left,Tree2->right)&&Symmetry(Tree1->right,Tree2->left);
            }
            return false;
        }
        bool isSymmetric(TreeNode* root) {
            if(root==NULL) return true;
            if(Symmetry(root->left,root->right)){
                    return true;
            }
            return false;
        }
    };
    //sc:o(1),tc:o(n)