/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution {

  public:
    Node* sortList(Node* head) {
        // Your Code Here
        Node*prev=head;
        Node*cur=head->next;
        while(cur!=NULL){
            if(cur->data<0){
                prev->next=cur->next;
                cur->next=head;
                head=cur;
                cur=prev->next;
            }else{
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};