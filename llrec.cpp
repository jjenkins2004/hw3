#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
        if (head == nullptr) {
            smaller = nullptr;
            larger = nullptr;
            return;
        }
        Node* temp = head;
        head = nullptr;
        smaller = nullptr;
        larger = nullptr;
        if (temp->val > pivot) {
            larger = temp;
            llpivot(temp->next, smaller, larger->next, pivot);
        } else {
            smaller = temp;
            llpivot(temp->next, smaller->next, larger, pivot);
        }
}