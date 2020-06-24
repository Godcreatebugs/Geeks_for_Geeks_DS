#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
};
/* To delete a node from linked list :
1. We need access to previous_element to the node that has to be deleted and key for the element to be deleted.
2. And as we dont know the pointer to element that needs to be deleted we have to iterate and this has to be O(n) operation.
3. We have to create a temp node(which is like must have when we are iterating)
*/
//if condition if we have found the key on the first node then we dont have to iterate through while loop

void deleteElement(Node** head_ref,int key){
  //head_ref for begining and key to compare the data in nodes
  Node* temp = *head_ref; //derefrence the head_ref to get head_pointer
  Node* previous_node =NULL; //previous_node to keep track

  if (temp==NULL) return; //nothing to delete from null linkedlist
  else{
    while (temp !=NULL && temp->data != key){
      previous_node = temp;
      temp = temp->next;
    }// the second condition checks wether if we have reached last element return nothing.
    if (temp->data == key && temp != NULL){
      previous_node->next = temp->next;
      free(temp);
    }
    else return;
  }
}

//print function for the pointer
void PrintList(Node *n){
  while (n!=NULL) {
    cout<<n->data <<" ";
    n = n->next;
  }
  cout<<"\n";
}

//Drivers code
//COMMENT--->>It works fine
int main(){
    Node* head = NULL;
    Node* first =NULL;
    Node* second =NULL;
    //Populating the nodes
    // A GREAT MISTAKE THAT YOU HAVE DONE HERE WHICH YOU ARE LIKELY TO REPEAT IS
    // YOU SPECIFIED POINTERS BUT NOT ACTUAL MEEMORY ON THE HEAP
    head = new Node();
    first = new Node();
    second = new Node();

    head->data =1;
    head->next =first;

    first->data = 2;
    first->next = second;

    second->data =3;
    second->next =NULL;
    PrintList(head);
    deleteElement(&head,3);
    PrintList(head);
    return 0;

}
