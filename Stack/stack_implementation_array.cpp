#include <bits/stdc++.h>
using namespace std;

/*
Stack is a linear abstract DS which performs simple functions but maintaining order.
Push, Pop, Top/Peek and isEmpty are common functions that are Implemented using.
Stack can be implemented using array or linkedlist (another linear data structure)
1. Push - If there is space element put at the Top
2. Pop -  If there is an element in stack take out top most element
3. top/Peek - Return top element
4. isEmpty() - Check wether stack is emplty or not
All this functions are O(1) and no loops are involved and this DS use LIFO

Practical implementation is web browser, tree traveral, where you need to retrieve cache memory

 */

#define maximum 1000 //macro for stack Size and array size is fixed and we can not do anything about it..
// using array implementation and making class
class Stack{
  int a[maximum]; // top relates to number of elements and private so don't temper directly, use public methods
public:
  int top; //INTIATE with -1
  Stack(){top = -1;} // a constructor
  // no other ops defined for stack and these are O(1) ops. No loop involved
  bool Push(int new_element);
  int Pop();
  int Top();
  bool isEmpty();
};

bool Stack::Push(int new_element){
  //push only if stack has space otherwise it is stack overflow
  if (top>=999){// size full
    cout<<"Stack Overflow."<<"\n";
    return false;
  }
  else{
    a[++top] = new_element; // change the index and upload element directly
    cout<<new_element<<" : has been pushed into stack."<<"\n";
    return true;
  }
}

int Stack::Pop(){
  if (top<0) {
    cout<<"Stack Underflow"<<"\n";
    return -1;
  }
  else{
    return a[top--]; //master move as we have returned currenmt value and reduced top's value in one line
    cout<<"Pop operation is succesful."<<"\n";
  }
}

int Stack::Top(){
   //base condition
   if (top<0) {
     cout<<"Stack is Empty."<<"\n";
     return -1;
   }
    return a[top];
    //basic difference bw top and pop is for top we are just returning the upper most dishes but we are not removing it from stack
}

bool Stack::isEmpty(){
  if (top<0) return true;
  else return false;
}
//drivers code
int main(){
  Stack stack; //default top is -1 , constructor
  stack.Push(10);
  stack.Push(20);
  stack.Push(30);
  stack.Push(40);
  stack.Pop();
  stack.Top();
  stack.isEmpty();
}
