/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL ||head->next==NULL) return head;
        DLLNode*prev=NULL;
        DLLNode*temp=head;
        while(temp!=NULL){
            DLLNode* nextnode=temp->next;
            temp->next=prev;
            temp->prev=nextnode;
            prev=temp;
            temp=nextnode;
            
        }
        return prev;
    }
};