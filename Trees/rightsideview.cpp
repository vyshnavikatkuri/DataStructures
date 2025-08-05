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
        vector<int> rightSideView(TreeNode* root) {
            vector<int>ans;
            queue<TreeNode*>q;
            q.push(root);
            if(root==NULL) return ans;
            while(!q.empty()){
                int data=0;
                int level=q.size();
                for(int i=level;i>0;i--){
                    TreeNode* node=q.front();
                    q.pop();
                    data=node->val;
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                }
                ans.push_back(data);
            }
            return ans;
        }
    };
    //tc:o(n),sc:o(n)