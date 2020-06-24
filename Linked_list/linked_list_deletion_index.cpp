#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
};
/* To delete a node from linked list(Using Index) :
1. We need an iteration untill counter reaches to position and temp variable to hold current_node,
2. And make previous to use link unlink and if we have hit the counter than free temp and link temp->next to prev->next
*/
//if condition if we have found the key on the first node then we dont have to iterate through while loop

void deleteElement_Index(Node** head_ref,int position){
  //head_ref for begining and key to compare the data in nodes
  Node* temp = *head_ref; //derefrence the head_ref to get head_pointer
  Node* previous_node =NULL; //previous_node to keep track

  if (temp==NULL) return; //nothing to delete from null linkedlist
  else{
  int counter =0;
    while(counter != position){
      previous_node = temp;
      temp = temp->next;
      counter++;
    }//while
    if (counter == position){
      previous_node->next = temp->next; //unlink temp
      free(temp); //free temp
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
    deleteElement_Index(&head,2);
    PrintList(head);
    return 0;

}
