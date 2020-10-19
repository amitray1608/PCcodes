#include<bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  struct Node *l, *r;
};

struct Node *newnode(int val) {
  //create a new node;
  struct Node * node = (struct Node*) malloc(sizeof(struct Node));
  node -> val = val;
  //assign null to both the child.
  node -> l = node -> r = NULL;
  //the newly created node
  return node;
}

//searching in the tree
struct Node *search(struct Node * root, int val) {
  if(root == NULL or root -> val == val)
    return root;
  //search left
  if(root -> val > val)
    return search(root->l, val);
  //search right;
  else
    return search(root->r, val);
}


//inorder traversal for sorted data
void print(struct Node *root) {
  if(root == NULL)
    return;
  //go left
  print(root -> l);
  //print data
  cout << root -> val << ' ';
  //go right
  print(root -> r);
}

struct Node * insert(struct Node *node, int val) {
  //check if it came to an end.
  if(node == NULL)
    return newnode(val);
  //check if the value of the current node is less greater.
  else if(val < node->val)
    node -> l = insert(node -> l, val);
  //check the same for the right.
  else if(val > node -> val)
    node -> r = insert(node -> r, val);
  //return the root after insertion.
  return node;
}

int main() {
  //no of nodes to be inserted in the tree
  int n;
  cin >> n;
  //create the root node and assign null
  struct Node * root = NULL;
  //take the input
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    //call insert function.
   root = insert(root, x);
  }
  //print in sorted order
  print(root);
  int x;
  cin >> x;
  struct Node *at = search(root, x);
  if(at->val == x)
    cout << "Value found " << endl;
  else
    cout << "No Value found" << endl;
  return 0;
}
/*
5
8 3 4 5 1
6
*/

