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
  // **head_ref is basically a pointer to pointer and derefrence of head_ref leads us to same pointer as head_pointer aka first pointer
  // we have to make a new Node for incoming node and insert data for the same

  Node* new_node = new Node(); //space on the heap for new_node
  new_node->data = new_data; // data is inserted in the node
  new_node->next = *head_ref; //means you put new_node's next to where head was pointing first and that is of course older first Element
  *head_ref = new_node; // and head_ref should point to new_node
 //This is Slick AF and runs into O(1).
}

void AddBetween(Node* previous_node,int new_data){
  //if a null linkedlist
  if(previous_node ==NULL){
    cout<<"This is null linkedlist and cannot add elemnts,refer to push method. ";
    //DOUBT:: Technically we can as we just have to add this as a new_node...
    return;
  }
  Node *new_node = new Node(); //allocating new_node on heap
  new_node->data = new_data; //data allocated
  new_node->next = previous_node->next; //the nect element of new_node will be previous_node's next Node
  previous_node->next = new_node; //and previous_node has been directed to new_node

}

void Append(Node** head_ref,int new_data){
  //this is O(n) operation as we have to loop through untill we reach last Element
  Node* new_node = new Node(); //allocated memory on heap for Node object
  new_node->data = new_data; //new_node has a data now
  new_node->next = NULL; //last element point to NULL
  //considering possibility that linkedlist  is null and the operation is failed same case as AddBetween
  if (*head_ref == NULL){
    cout<<"linkedlist is empty and this operation is invalid please consdider. ";
    return;
  }
  Node* last =*head_ref;
  while(last->next !=NULL){
    last =last->next;
  }
  last->next =new_node;
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
