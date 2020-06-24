#include <bits/stdc++.h>
using namespace std;

/*for any C++ code doubly linkedlist is presented using class and with c it is struct
 Doubly Linkedlist gives us opportunity to travel bidirectional and due to its previous pointer we
 can add node before given node(Advantage)
 But it requires more space to satore another pointer(disadvantage)
*/


class Node{
public:
  int data;
  Node* next;
  Node* previous;
};

//1st propcess is to push node at begining
void Push(Node** head_ref,int new_data){
      Node* new_node = new Node(); //space for node data available
      new_node->data = new_data; //node data available
      new_node->next = *head_ref; // address of pointer to first element before editing happened
      new_node->previous = NULL; // now our first node is new_node and attribute change to NULL
      *head_ref = new_node; //and head pointer changed to new_node

      //done with O(1)
}

//2nd after a given node same as singly linkedlist
void AddAfter(Node* previous_node, int new_data){
   // this is a little delicate as you have to mess around 2 pointers now
   if (previous_node ==NULL) {
     return;
     cout<<"Either linkedlist is empty or previous_node is first node and that is head";
     return;
     //Not a valid operation for last element patch up as this is already a different operation.
   }
   Node* new_node = new Node();//space on heap for new node
   new_node->data = new_data;
   Node* next_node = previous_node->next;//accesing next element as we have to change its charactristic
   new_node->next = previous_node->next;// next attribute of new_node
   next_node->previous = new_node; // next-node has to change its previous(not next)
   new_node->previous = previous_node; //previous should point to previous_node
   previous_node->next = new_node;// and previous_node should point to new_node

   //Done with O(1)
}

//3rd At last append
void Append(Node** head_ref,int new_data){
  // as we dont have a pointer to last element available we have to iterate
  // if thats not the case then we can grab that pointer and perform simple operation


  Node* new_node = new Node(); //made space on heap for new_node
  new_node->data = new_data;
  new_node->next = NULL; //attributes set for new_node except previous
  if (*head_ref ==NULL){
    *head_ref = new_node;
    new_node->previous =NULL;
    //special case consideration where list is empty.
  }
  Node* last = *head_ref; // this variable will help to navigate

  while(last->next != NULL){
     last= last->next;
  }//if we have reached the end(as last node points to null
    last->next = new_node; // last should point to new_node
    new_node->previous = last;

   //Done with O(1)
}
//4th Add an elemnt before some Node
void AddBefore(Node* next_node, int new_data){
  // This is basically an advantage of bidirection
  // In singly linkedlist we can not do that
  Node *new_node  = new Node(); //allocating space for new_element
  new_node->data = new_data; //data is given
  if (next_node == NULL){
     return;
     // You can not add before either first element or NULL as we have a seperate element for that
  }
  Node* previous_node = next_node->previous ; //identify previous_node before editing
  new_node->next = next_node; // new_node should point to next_node in forward
  next_node->previous = new_node; // next_node should point at new_node in backward
  new_node->previous = previous_node; // new_node should point to previous_node in backward
  previous_node->next = new_node;// previous_node should point to new_node
}
void PrintNode(Node *n){
  while (n !=NULL){
    cout<<n->data<<" ";
    n =n->next;
  }
  std::cout<< '\n';
}
int main(){
  //allocating the pointers
    Node* head;
    Node* first;
    Node* second;

    head = new Node();
    first = new Node();
    second = new Node();

    head->data =1;
    head->next = first;
    head->previous = NULL;

    first->data =2;
    first->next = second;
    first->previous = head;

    second->data =4;
    second->next = NULL;
    second->previous = first;

    PrintNode(head);
    Push(&head,-1);
    PrintNode(head);
    AddAfter(first,3);
    PrintNode(head);
    Append(&head,-6);
    PrintNode(head);
    AddBefore(head,-5);
    PrintNode(head);
}
