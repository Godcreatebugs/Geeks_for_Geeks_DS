#include <bits/stdc++.h>
using namespace std;

//for any C++ code linkedlist is presented using class and with c it is struct
class Node{
public:
  int data;
  Node* next;
};
//Linked List-Set 2(Inserting Node)
/*
Insertion and Deletion is advantage for linkedlist and you just have to move pointers 2 times and you are done
Hence this is O(1) operation. We can add at front at back or anywhere in between
BUT indexing linkedlist is not possible and hence we have to move forward checking each node and that is O(n) operation
This is the disadvantage of linkedlist.
*/
//Add a new Node at front

void Push(Node **head_ref,int new_data){
   //this is a four step process and head_ref is pointer to the address of head Node
   Node *new_node =new Node(); //memory allocated on heap for the new_node
   new_node->data = new_data;//data is set as new_data
   new_node->next = *head_ref;
   *head_ref = new_node;
   /*it is a little complicated but first 2 steps are understandable which translates to that I am allocating
   memory on the heap and modified its data using function parameter
   head_ref must be understood through and head_ref is a pointer to the address of head and here is how we use it
   ---> We derefrence the pointer to get the address of head pointer and which contains the address of first node
   so first process is to point our next attribute of new_node to first element of linkedlist
   and now we the address of now the new_node should point to head_refs address
    Damn! thats slick AF
   */
}

void AddBetween(Node *previous_node, int new_data){
   if (previous_node == NULL){
     cout<<"previous node can't be null. ";
     return;
   }
   Node* new_node = new Node();//allocating memory for Node on heap
   new_node->data = new_data;//data has been Given
   new_node->next = previous_node->next; //first making link between new_node and next via previous_node attribute is important
    previous_node->next = new_node;
}

void Append(Node** head_ref,int new_data){ //this is O(n) process but we can make it O(1)
  Node* new_node = new Node();//allocating memory on heap for new_node
  new_node->data = new_data; //allocating new_data
  new_node->next = NULL; //it should point to NULL as this is the last element
  //make a temp variable last to iterate through the linkedlist
  Node* last = *head_ref;
  if(*head_ref == NULL){
    //NULL linkedlist
    cout<<"This is null linkedlist. ";
    return;
  }

  while(last->next !=NULL){
     last = last->next;
  }
     last->next =new_node;
}

void PrintNode(Node *n){
  while (n !=NULL){
    cout<<n->data<<" ";
    n =n->next;
  }
}
int main(){
 //  Node *head=NULL; //Always first element should be head
 //  Node *first=NULL;
 //  Node *second=NULL;
 //
 // // now that we have declared the pointers to node lets allocate memory for the nodes in heap dynamically
 // //pointers will be used to keep track of these memory location as linkedlist is basically disjoint location
 //
 //  head = new Node();
 //  first =new Node();
 //  second = new Node();
 //  //now using head you   will allocate value to integer data;
 //
 //  head->data =1;
 //  head->next = first;// connecting to next node
 //
 //  first->data =2;
 //  first->next = second;
 //
 //  second->data =3;
 //  second->next =NULL;

  Node* head =NULL;
  Append(&head,1);
  PrintNode(head);
  return 0;
}
