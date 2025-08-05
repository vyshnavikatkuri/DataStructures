#include <bits/stdc++.h>
using namespace std;
// User function template for C++


struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node*oddhead=NULL;
        Node*evenhead=NULL;
        Node*eventail=NULL;
        Node*oddtail=NULL;
        Node*temp=head;
        while(temp){
            if(temp->data%2!=0){
                if(oddhead==NULL){
                    oddhead=oddtail=temp;
                }else{
                    oddtail->next=temp;
                    oddtail=oddtail->next;
                }
            }else{
                if(evenhead==NULL){
                    evenhead=eventail=temp;
                }else{
                    eventail->next=temp;
                    eventail=eventail->next;
                }
            }
            temp=temp->next;
        }
        if(eventail){
            eventail->next=oddhead;
        }
        if(oddtail){
            oddtail->next=NULL;
        }
        return (eventail!=NULL)?evenhead:oddhead;
        
        
    }
};