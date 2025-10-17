#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  smaller=NULL;
  larger=NULL; //handles unknown garbage
  if (head == NULL){
    return;
  } // base case
  else{
    if((head->val)<=pivot){
      smaller=head; //distribute memories
      head=head->next; //traverse in a fashion so that at the end the original list is not preserved
      smaller->next=NULL;
      llpivot(head,smaller->next,larger,pivot); //recursive
    }
    else{
      larger=head;
      head=head->next;
      larger->next=NULL;
      llpivot(head,smaller,larger->next,pivot);
    }
  }
}
