#include <bits/stdc++.h>
using namespace std;

/*
Queue are the abstract DS where you can implement using array(hard) and linkedlist(easy).
4 Primary operation are deque, enque, front and rear
1. Deque - Element from the first pops out
2. Enque - Element at last joined
3. Front - get first element of que (Beginning)
4. Back - Get rear element of que
This all are O(1) opearions.
to implement que using array you can use class and capacity is fixed
# You have to use capacity and size as factors defined and we have 2 use 2 poimters
one at the back and one at the front to keep track record.
*/

class Queue{
public:
  int front,rear,size;
  unsigned capacity; //IDK why unsigned
  int* array; //another implementation of array
  //as always you can use constructor or function to make a Queue
  //function can deal with pointers and hence is memory efficient

 Queue* MakeQueue (unsigned capacity){
   Queue* queue =  new Queue(); // allocating space for que
    queue->capacity = capacity; // capacity assigned
    queue->front= queue->rear = 0 ;// both pointers start at 0.

  queue->array = new int[sizeof(int) * queue->capacity];
  return queue;
 }

bool isFull(Queue* queue){
  return queue->size == queue->capacity;
}

bool isEmpty(Queue* queue){
  return (queue->size==0);
}

int Front(Queue* queue){
   if (isEmpty(queue)) return INT_MIN;
    return queue->front;

}

int Back(Queue* queue){
  if(isEmpty(queue)) return INT_MIN;
  return queue->rear;
}
// void as in we just need to join the element and for deque we need return int
void EnQue(Queue* queue, int data){
    //check wether you are going out of size, we call it que overflow
    if (isFull(queue)) return;
    queue->array[++size] = data;//data enqued
    front++;
    cout<<data<<"enqued in que";
}

};

int main(){
  Queue Q; //amking an object
  Q.MakeQueue(5);

}
