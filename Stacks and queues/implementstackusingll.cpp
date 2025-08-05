#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Stack{
    Node* head;
    public: 
    Stack(){ head=NULL;}
    void push(int val){
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
    }
    int pop(){
        if(head==NULL) return -1;
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        return temp->data;
        free(temp);
    }
    int top(){
        return head->data;
    }
    bool isempty(){
        return head==NULL?true:false;
    }
    int main(){
       Stack st;
       st.push(3);
    }


};