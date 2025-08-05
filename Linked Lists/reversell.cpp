#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int data){
        this->val=data;
        this->next=NULL;
    }
    Node(){};
};
Node* reversell(Node* head){
    Node* temp=head;
    Node* next;
    Node* prev=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;

}
int main(){
   Node* head=new Node(1);
   head->next=new Node(2);
   Node* newhead=reversell(head);
   while(newhead!=NULL){
    cout<<newhead->val<<"->";
    newhead=newhead->next;
   }
   return 0;
}
