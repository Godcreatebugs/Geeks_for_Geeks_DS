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
  int capacity; //IDK why unsigned
  int* array; //another implementation of array
  //as always you can use constructor or function to make a Queue
  //function can deal with pointers and hence is memory efficient

 Queue* MakeQueue (int capacity){
   Queue* queue =  new Queue(); // allocating space for que
    queue->capacity = capacity; // capacity assigned
    //indexing starts from 0 and hence rear is where we deque
    queue->front = queue->size = 0 ;// intial size is 0 and front is 0 as well
    //This is a peculiar move to assign a rear pointer to right most element of the array but enque and deque ops will make sense.
    queue->rear  = queue->capacity - 1;//size
    queue->array = new int[sizeof(int) * queue->capacity]; // array size has been allocated and this is fixed size which dont go beyond capacity
  return queue;
 }

bool isFull(Queue* queue){
  return (queue->size == queue->capacity);
}
bool isEmpty(Queue* queue){
  return (queue->size==0);
}
bool Back(Queue* queue){
  if(isEmpty(queue)) return INT_MIN;
  //you need to indexing to an array to get an element and the line below is wrong implementation
  //return queue->front;
    return queue->array[queue->rear];
}
//Front Operation
int Front(Queue* queue){
   if (isEmpty(queue)) return INT_MIN;
    //return queue->front;
    return queue->array[queue->front];
}
// void as in we just need to join the element and for deque we need return int
void EnQue(Queue* queue, int data){
    /*
    FIRST ENQUE WILL START AT REAR AS WE KNOW THAT WE ATTACH ELEMENT AT REAR END IN QUE
    So, que->array[que->rear] = int would have worked
    and this has to be set as a front which is again at the begining of array before initalization
    Now, when we again join the element (After empty array and adding one element) we want to join the element after the front but doing same op
    once again hasn't changed the rear yet and that is why it wont work
    [ , , , ,  ]
     |Front   |Rear
     after adding element
     [ 1, , , , ]
      |Front = Rear = Array shown
      [ 1,2,     3, , ]
        |Front    |Rear
   //front has stayed at the same place meaning dequeing happens from indexing 0 , makes it valid op

    [ 3,      2 ,  , , ,]
      |Rear   |Front

    and this can be implemented using circular thing.
    */
 // if capacity is full you cant enque
    if (isFull(queue)){
      cout<<"Que is full, capacity reached. "<<endl;
      return;
    }
    //joining happens at rear and AT THE BEGINING OF ARRAY
    queue->rear = (queue->rear +1)  % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size ++;
    cout<<data<<" has been enqued. "<<endl;
};

void DeQue(Queue* queue){
    if (isEmpty(queue)) {
      cout<<"Queue is already empty. "<<endl;
      return ;
    }
    //front has been moved one index begind
    //The reason there is  front + 1 bcz front pointer points at begining of array and we have to move it forward
    //int iteam = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    //cout<<iteam<<" has been dequed. "<<endl;
    queue->size--;

}
};
int main(){

  Queue q; //making an object
  Queue* queue = &q;
  queue->MakeQueue(5);
  queue->EnQue(queue,1);
  queue->EnQue(queue,2);
  queue->EnQue(queue,3);
  queue->DeQue(queue);
  // queue->Front(queue);

}
