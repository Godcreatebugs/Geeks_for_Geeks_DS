#include <bits/stdc++.h>
using namespace std;

/*
Que Implementation using linkedlist:
By far this is the most easy method cuz
You dont have to worry about memory management and just need 2 pointers to keep track
We can call it front and rear to point those elements accordingly.

No problem for size variation as no overflow or underflow
*/

struct Node{
  //Node structure
  int data;
  Node* next;

  // from GFG solution we can say one thing and that is even when we call function the constructor makes an object
  Node(int x){ //constructor
    data = x;
    next=NULL;
  }
};

class Queue{
public:
  Node* front, *rear; //intialising with null
  Queue(){
    front=rear=NULL; //a constructor with front and rear null at begining
  }

  void Enque(int new_data){

    Node* new_node = new Node(new_data);// allocating memory
    //if not even a single element inserted
    new_node->data = new_data;
    if(rear==NULL){
      cout<<"Empty Que but "<<new_node->data<<" Linked. "<<endl;
      rear=front=new_node;
      return;
    }
    rear->next = new_node;
    rear = new_node;
    cout<<new_node->data<<" Linked."<<endl;
  }
  void Deque(){
    if (front==NULL) return; // empty ll
    //Temperorary Node to delete element
    Node* temp = front;
    //remember that connection are from front to back
    cout<<front->data<<" Delinked."<<endl;
    front =front->next;
    //after this if que becomes empty
    if(front== NULL) rear=NULL; //both goes for null
    free(temp);//free up temp variable
  }
};


int main(){
  Queue q;
  q.Enque(5);
  q.Enque(3);
  q.Enque(2);
  q.Enque(1);
  q.Deque();
  cout<<"Front element is: "<<(q.front)->data<<endl;;
  cout<<"Last element is: "<<(q.rear)->data<<endl;

}
