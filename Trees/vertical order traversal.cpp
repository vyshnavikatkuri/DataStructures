class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>>ans;
            map<int,map<int,multiset<int>>>nodes;
            if(root==NULL) return ans;
            queue<pair<TreeNode*,pair<int,int>>>q;
            q.push({root,{0,0}});
            while(!q.empty()){
                    auto p=q.front();
                    q.pop();
                    TreeNode* node=p.first;
                    int ver=p.second.first;
                    int lev=p.second.second;
                    nodes[ver][lev].insert(node->val);
                    if(node->left!=NULL){
                        int newv=ver-1;
                        int newl=lev+1;
                        q.push({node->left,{newv,newl}});
                    }if(node->right!=NULL){
                        int newv=ver+1;
                        int newl=lev+1;
                        q.push({node->right,{newv,newl}});
                    }
                }
            for(auto p:nodes){
                vector<int>col;
                for(auto q:p.second){
                    col.insert(col.end(),q.second.begin(),q.second.end());
                }
                ans.push_back(col);
            }
            return ans;
            
    
        }
    };
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
           auto p=q.front();
           q.pop();
           TreeNode* node=p.first;
           int ver=p.second.first;
           int level=p.second.second;
           mp[ver][level].insert(node->val);
           if(node->left!=NULL){
                int newv=ver-1;
                int newl=level+1;
                q.push({node->left,{newv,newl}});    
           }
           if(node->right!=NULL){
            int newv=ver+1;
            int newl=level+1;
            q.push({node->right,{newv,newl}});
           }
        }
        for(auto p:mp){
            vector<int>col;
            for(auto t:p.second){
                col.insert(col.end(),t.second.begin(),t.second.end());
            }
            ans.push_back(col);
        }
        return ans;
       

    }
};
    // Time Complexity for Insertion into Map
    // In the given code, the data structure used for storing nodes is:
    
    // cpp
    // Copy
    // Edit
    // map<int, map<int, multiset<int>>> nodes;
    // This is a nested map where:
    
    // The outer map<int, ...> uses vertical as the key.
    
    // The inner map<int, multiset<int>> uses level as the key.
    
    // The multiset<int> stores node values at the same vertical and level.
    
    // 📌 Insertion into Map Complexity
    // Insertion into map<int, T> takes O(log K), where K is the number of keys in the map.
    
    // In this case:
    
    // Outer Map (Vertical Levels) → O(log V) where V is the number of unique verticals.
    
    // Inner Map (Levels) → O(log L) where L is the number of unique levels for a given vertical.
    
    // Insertion into Multiset → O(log N) for maintaining the sorted order of values.
    
    // ✅ Total Time for Insertion
    // For each node insertion:
    
    // 𝑂
    // (
    // log
    // ⁡
    // 𝑉
    // +
    // log
    // ⁡
    // 𝐿
    // +
    // log
    // ⁡
    // 𝑁
    // )
    // O(logV+logL+logN)
    // Where:
    
    // V ≤ N in the worst case (each node has a unique vertical level).
    
    // L ≤ N in the worst case (each node has a unique level).
    
    // N is the number of nodes.
    
    // 𝑂
    // (
    // log
    // ⁡
    // 𝑁
    // +
    // log
    // ⁡
    // 𝑁
    // +
    // log
    // ⁡
    // 𝑁
    // )
    // =
    // 𝑂
    // (
    // log
    // ⁡
    // 𝑁
    // )
    // O(logN+logN+logN)=O(logN)
    // 📌 Why Multiset?
    // Multiset maintains the node values in sorted order, which is useful for scenarios where multiple nodes exist at the same (vertical, level).
    
    // It ensures efficient insertion and retrieval.
    
    // ✅ Final Conclusion
    // Time Complexity for Insertion into Map → O(log N) per node.
    
    // Since there are N nodes, the total insertion time is:
    
    // 𝑂
    // (
    // 𝑁
    // log
    // ⁡
    // 𝑁
    // )
    // O(NlogN)