//linkedlist implementation of stack
#include<bits/stdc++.h>

using namespace std;



//methods for stacknode class

//make a new node AGAIN METHOD NOT NEEDED BUT MAKES PUSH POP EASY
//You also could have used a default constructor...
/*
One misconception here is that the last element is pointing to null which is wrong
it is actually other way around cuz your top changes every single time hence top pointer is a
specially alocated pointer which changes, and root or head is actually have NULL as a value.
Here, I am implementing using struct
*/

struct Node{
  int data;
  Node* next;
};

class Stack{
public:
  //top is not node, it is just a pointer pointing at top, make sense right?
  struct Node* top;
  //Push Method
  void Push(int new_data){
      //need temo variable as 3rd party variable
      Node* temp;
      temp = new Node(); //allocating memory on heap
      //rare case but you need to include this
      if (!temp){
        cout<<"A rare condition that heap has no space left meaning stack overflow. "<<endl;
        return;
      }
      temp->data = new_data;
      temp->next = top;
      top = temp;  //temp becomes the top now
      cout<<"Operation succesful "<<new_data<<" Has been Pushed."<<endl;
  }

  void Pop(){
    Node *temp;
    temp = new Node();
    if (!temp){
      cout<<"A rare condition that heap has no space left meaning stack overflow. "<<endl;
      return ;
    }
    if (top == NULL){
      cout<<"Stack Underflow."<<endl;
      return ;
    }
    temp = top;
    cout <<temp->data <<"is poped out. "<<endl;
    top = top->next; //most imporatnt step as we have stepped doen top
    free(temp); //free memory

  }
// Peek/Top Function
  int Top(){
    if (top == NULL){
      cout<<"Stack Underflow. Invalid Operation. "<<endl;
      return -1;
    }
    cout<<top->data<<endl;
    return top->data;
  }
//isEmpty() Function
bool isEmpty(){
  return top==NULL;
}

//print the stack

void PrintStack(){
  Node* temp;//a temporary node to navigate through stack
  temp = top;
  if (top ==NULL) {
    cout<<"No elements in the satck."<<endl;
    return;
  }
  while(temp !=NULL){
    cout<<temp->data;
    temp = temp->next;
}

}
};
int main(){

  Stack S;
  S.Push(1);
  S.Push(2);
  S.Push(3);
  S.Push(4);
  S.Top();
  S.Pop();
  S.isEmpty();
  S.PrintStack();
}
