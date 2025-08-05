#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;Node*left;Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
bool getpath(Node* root,vector<int>&arr,int target){
    if(root==NULL) return false;
    arr.push_back(root->val);
    if(root->val==target) return true;
    if(getpath(root->left,arr,target)||getpath(root->right,arr,target)){
        return true;
    }
    arr.pop_back();
    return false;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->right=new Node(7);
    root->right->left=new Node(6);
    vector<int>arr;
    if(getpath(root,arr,7)){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<"->";
        }
    }else{
        cout<<-1;
    }

}