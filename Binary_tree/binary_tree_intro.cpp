#include <bits/stdc++.h>

using namespace std;

/*
Binary trees are special cases of tree where each node can have at most 2 children.
Namely right and left child. Pointers are used to connect them and used to store heirarchial data.
- For example file system in computer is an heirarchy ,
- Implemented using class or struct that contains data and right and left pointer
- Example is
file system
-----------
     /    <-- root
  /      \
...       home
      /          \
   ugrad        course
    /       /      |     \
  ...      cs101  cs112  cs113

- Size is dynamic and we can insert and delete element whenever we need unlike arrays
- Insertion, Deletion is moderate faster than array and slower than linkedlist.
- Access/Search is moderate  -- faster than LL and slower than array.
*/

//using struct rather than class and not a big difference for now
struct Node {
  int data;
  Node* left;
  Node* right;
};

// IT IS IMPORATNT TO MAKE A SEPERATE FUNCTION TO INTIATE THE NODE AS WE DONT WONT STRUCT TO BE INTIATE WITH NULL
// SO MAKE A FUNCTION WHICH TAKE INT AND MAKE A NODE WITH LEFT AND RIGHT AS NULL
// remember for struct we have to mention struct before function
Node* NewNode(int new_data){
     Node* new_node = new Node(); //memory allocation before allocating actual data
     new_node->data = new_data; //data made available
     new_node->left =NULL;
     new_node->right = NULL;
     return new_node;
}

// void PrintTree(Node* root){
//   while (root->left !=NULL || root->right !=NULL){
//     if (root->left !=NULL){
//       root = root->left;
//     }
//     else if(root->right != NULL){
//       root = root->right;
//     }
//   }
// }


//drivers code

int main(){
   Node *root = NewNode(1); // pointer to root
//  tree to be made
  //----
//        1    <-- root
//      /   \
//     2     3
//    /
//   4;

  // root node
root->left  = NewNode(2);
root->right = NewNode(3);
root->left->left  = NewNode(4); // navigation made easy using pointers plus seemed no other way

}
