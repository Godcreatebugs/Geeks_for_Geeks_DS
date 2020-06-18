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
// creating a tmp vaiable which hold head_pointers value to naviagte
// and to delete the elemnt we also need previous_node value
Node* tmp = *head_ref; // *head_ref is derefrencing the head_ref and this gives us head_pointer pointing to very first element
Node* previous; //to link previous to next and here we know where we are

//if condition if we have found the key on the first node then we dont have to iterate through while loop
if (tmp!=NULL && tmp->data==key){
  //tmp and head_pointer are both pointing in the same direcction
    *head_ref= tmp->next;// Head pointer will move towards the next element
    free(tmp); //delete temp pointer
    return;
    // Dont have idea wether that deletes actual node or not
}//if

while (tmp !=NULL  && tmp->data==key){
  prev = tmp // moving temp to previous and temp to ahead
  temp =temp->next;
}
if (tmp ==NULL) return; // if we havent found the key and reached at the end of linkedlist
//or else we have found key then you unlink tmp and free it and previous should point to next element in linkedlist
prev->next = tmp->next;
free(tmp);//free up tmp pointer

}

//print function for the pointer
void PrintList(Node *n){
  while (n->next !=NULL) {
    cout<<n->data;
    n = n->next;
  }
}

int main(){
  
}
