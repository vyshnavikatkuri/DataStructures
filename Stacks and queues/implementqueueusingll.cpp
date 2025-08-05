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
class Queue{
    public:
    Node*front=NULL;
    Node*rear=NULL;
    bool isEmpty(){
        if(front==NULL) return true;
        else return false;
    }
    void enqueue(int x){
        Node* newnode=new Node(x);
        if(this->isEmpty()){
            front=rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=newnode;
        return;
    }
    int dequeue(){
       if(front==NULL) return-1;
       Node* temp=front;
       front=front->next;
       free(temp);
       if(front==NULL) rear=NULL;
       return front->data;
    }
    int getfront(){
        if(this->isEmpty()){
            return -1;
        }
        return front->data;
    }

};