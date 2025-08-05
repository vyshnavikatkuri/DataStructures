#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // int length(Node*head){
    //     int cnt=0;
    //     Node*temp=head;
    //     while(temp){
    //         c++;
    //         temp=temp->next;
    //     }
    //     return c;
    // }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node*p1=head1;
        Node*p2=head2;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1==NULL) p1=head2;
            if(p2==NULL) p2=head1;
        }
        return p1;
        
    }
};