#include "llrec.h"
#include <cstddef>

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  if(head -> val <= pivot)
  {
    smaller = head;
    Node* temp = head -> next;
    head = NULL;
    llpivot(temp, smaller -> next, larger, pivot);
      
  }
  else if(head -> val > pivot)
  {
    larger = head;
    Node* temp = head -> next;
    head = NULL;
    llpivot(temp, smaller, larger -> next, pivot);
  }
}

/* If you needed a helper function, write it here */

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


