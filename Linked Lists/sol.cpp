#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int c){
        data=c;
        next=NULL;
    }
};
vector<Node*> solution(Node*head){
    Node*temp=head;
    Node*evenhead=NULL;
    Node*oddhead=NULL;
    Node*eventail=NULL;
    Node*oddtail=NULL;
    int i=0;
    while(temp){
        if(i%2==0){
            if(evenhead==NULL){
                evenhead=eventail=temp;
            }else{
                eventail->next=temp;
                eventail=eventail->next;
            }
        }else{
            if(oddhead==NULL){
                oddhead=oddtail=temp;
            }else{
                oddtail->next=temp;
                oddtail=oddtail->next;
            }
        }
        i++;
        temp=temp->next;
    }
    vector<Node*>lists={oddhead,evenhead};
    return lists;
}
void printlists(Node*head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    vector<Node*>lists=solution(head);
    for(int i=0;i<lists.size();i++){
        printlists(lists[i]);
        cout<<endl;
    }
    return 0;
}
