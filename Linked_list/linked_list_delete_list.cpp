#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
};
/* To delete entire linked list :
1. we need to iterate and have to make a temp variable and a previous to delete previous_node everytime
2. while loop untill we hit end(Null) and then delete then free temp and set head_ref to null

*/
//if condition if we have found the key on the first node then we dont have to iterate through while loop

void deleteList(Node** head_ref){
  //head_ref for begining and key to compare the data in nodes
  Node* temp = *head_ref; //derefrence the head_ref to get head_pointer
  Node* previous_node =NULL; //previous_node to keep track

  if (temp==NULL) return; //nothing to delete from null linkedlist
  else{
    while(temp != NULL){
      previous_node = temp;
      temp = temp->next;
      free(previous_node);
    }//while loop
     if (temp ==NULL){
       *head_ref = temp;
       free(temp);
     }
  return;
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
    deleteList(&head);
    PrintList(head);
    return 0;

}
