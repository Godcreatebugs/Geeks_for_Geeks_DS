#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* NewNode(int new_data){
     Node* new_node = new Node(); //memory allocation before allocating actual data
     new_node->data = new_data; //data made available
     new_node->left =NULL;
     new_node->right = NULL;
     return new_node;
}

// this is recursion solution and takes a lot of time(O(1)) but space taken is humongous.O(n) if we consider call size of the function then
// we have O(n) otherwise O(1).  
/*
Unlike arrays and linkedlist trees are heirarchial DS and can be traversed in different ways.
-> 3 ways are preorder,postorder and inorder
1. Inorder traversal
Here we start from left subtree, go to root and then again to the right subtree
Used in BST data structure where output will be ordered numbers.
Here are 3 steps to do inorder traversal.
1. Print the ledt subtree and call Inorder.
2. print root
3. Print right of the root and call Inorder once again
-> This comes out to be recursive solution and so will other methods.

OK!! So, listen to me it is a little tricky if you dont understand it,
for example, we will put root node in the function and it will say ok so find
IO(2) and IO(2) will say find IO(4)--> which is our temination condition cuz
we have hit the null at this point so, we trace back to tree and we will see that we are yest to be done with O(2)
and we will print out O(2) and we will move onto unfinished business which is right side of the root
Again THE QURKS OF THE THING IS THAT YOU MAKE HWIRARCHY OF CALLS
*/

void PrintInOrder(Node* root){
  if (root==NULL) return ;// base condition
  PrintInOrder(root->left); // left first (this is not one step process and it will continue untill hit leaf nodes)
  cout<<root->data<<" "; // print root data
  PrintInOrder(root->right); // rightsubtree
}

/*
2nd method to taverse is preorder or I would say up to down method of traversal
Here we use root first then left tree and right subtree and it is used to correct polish notation
*/

void PrintPreOrder(Node* root){
  if (root==NULL) return;
  cout<<root->data<<" "; //first root
  PrintPreOrder(root->left); //left subtree
  PrintPreOrder(root->right); // right subtree
  //refer to inorder to understand recursion
  //EXPECTED = 1 2 4 5 3
}

/*
3rd and last method for depth first Search algorithm is PostOrder Search where we
traverse to ledt subtree then right subtree and at last root.
So, for this function answer will be 4 5 2 3 1.
First we will go untill we have hit the left most element(Null condition is base condition) then we go  for right and
at last print node for example PO(2) will terminates to 4 first then PO(2) goes to right and then we print root
*/

void PrintPostOrder(Node* root){// THIS METHOD LOOKS LIKE LEVEL SEARCH BUT IT IS NOT
  if (root == NULL ) return; //base condition
  PrintPostOrder(root->left); //untill hit leaf node and after that go up
  PrintPostOrder(root->right); //then hit right childern
  cout<<root->data<<" "; // then the root
}
//drivers code
int main(){
   Node *root = NewNode(1); // pointer to root
//  tree to be made
  //----
//        1    <-- root
//      /   \
//     2     3
//    / \
//   4   5

  // root node
root->left  = NewNode(2);
root->right = NewNode(3);
root->left->left  = NewNode(4); // navigation made easy using pointers plus seemed no other way
root->left->right = NewNode(5);
PrintInOrder(root);
cout<<"\n";
PrintPreOrder(root);
std::cout<< '\n';
PrintPostOrder(root);
}
