//linkedlist implementation of stack
#include<bits/stdc++.h>

using namespace std;

class StackNode{
public:
  int data;
  StackNode* next;

//methods for stacknode class

//make a new node AGAIN METHOD NOT NEEDED BUT MAKES PUSH OP EASY
StackNode* NewNode(int new_data){
  StackNode* new_node = new StackNode(); // allocating memory
  new_node->data = new_data;
  new_node->next = NULL;
  return new_node;
}
//push op and unlike array it never goes out of limit
void Push(StackNode** root,int new_data){
//pointer to root is basically last to last poiner cuz last pointer points to not exactly NUll and that makes it intersting
  StackNode* new_root = NewNode(new_data); //use of NewNode Method
  // now consider root as a head_ref and cuz pointer at the root may or may not  be NULL and null at new_root and NULL
  //at root are different and this makes this one intersting, SO implement  it as it is head_ref
  new_root->next = *root; //THE REASON ITS NOT NULL IS CUZ VALUE AT ROOT POINTER MAYBE different And we can have dangling pointer
  *root = new_root; //root has been transfered to new_root
  cout<<new_data<<" :has been pushed."<<"\n";
}

int Pop(StackNode** root){ //address of root
    if (*root==NULL) return -1;
    //remember to delete an element we need   temp node and then we can free temp
    StackNode* temp = *root; //pointer of last Node is given to temp
    temp->next =
    return -1; 
}
int Top(StackNode* root){
  if (root == NULL) return -1;
  return root->data;
}
};
