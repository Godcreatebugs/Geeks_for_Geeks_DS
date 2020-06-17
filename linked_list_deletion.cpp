#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
};
// To delete a node from linked list, we need to do following steps.
// 1) Find previous node of the node to be deleted.
// 2) Change the next of previous node.
// 3) Free memory for the node to be deleted.

//mind you-- you just have key and hence a full blown O(n) check is needed from beginning
void DeleteElement(Node** head_ref,int key){
  //int key has to be deleted
  //tmp stores a pointer and *head_ref is an address
  //Hence tmp is a pointer pointing to address of pointer pointing to head node(basically first pointer)
Node* tmp = *head_ref;
Node* previous;
  //checking that if we only have 1 node and the data in their is key
  if (tmp != NULL && tmp->data ==key){
    //and if that is the case where on the first element we have key we change the head node's pointers
    *head_ref = tmp->next; //moving temporary to head_refs
    free(tmp);
    return; //I think this is the half way and we should have considered putting the head_ref to second element in linkedlist
  }


}

void PrintList(Node *n){
  while (n->next !=NULL) {
    cout<<n->data;
    n = n->next;
  }
}
