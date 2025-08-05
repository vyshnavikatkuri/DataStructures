#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to delete a node at given 1-based position.
    Node* deleteNode(Node* head, int x) {
        if (head == NULL) return NULL;

        // Case 1: Delete head
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return head;
        }

        // Traverse to the x-th node
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < x) {
            temp = temp->next;
            count++;
        }

        // If x is greater than the length of list
        if (temp == NULL) return head;

        // Re-link previous and next nodes
        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        return head;
    }
};
