#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};


class Solution {
  public:
    Node *addNode(Node *head, int p, int x) {
        Node*temp=head;
        int c=0;
        while(temp!=NULL && c<p){
            c++;
            temp=temp->next;
        }
        Node* newnode=new Node(x);
        //insertnode
        Node*tempnext=temp->next;
        temp->next=newnode;
        newnode->next=tempnext;
        newnode->prev=temp;
        
        if(tempnext!=NULL){
            tempnext->prev=newnode;
        }
        return head;
    }
};