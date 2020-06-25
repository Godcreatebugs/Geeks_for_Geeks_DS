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

#define top 1000 //macro for stack Size
// using array implementation and making class
class Stack{
  int top; // an element to initiate an stack and keep track of wether we have hit the bottom or not
public:
  Stack(int top = -1); // a constructor
  bool Push(int new_element);
  int Pop();
  int Top();
  bool isEmpty();
};
