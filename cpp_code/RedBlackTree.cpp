
/*
 Define right-leaning red-black BSTs as BSTs having red and black edges satisfying the following three restrictions:
i. Red links lean right only.
ii. No node has two red links connected to it.
iii. Every path from the root to a leaf has the same black depth.
(a) Rewrite the put() method, on page 439 of the Sedgewick book , 
    so that it works for right-leaning red-black trees instead of left-leaning red-black trees.
(b) Using a construction proof, show that for every right-leaning red-black tree there is a corresponding left-leaning red-black tree.
*/

#include<bits/stdc++.h>

using namespace std;
int size;

class Node {
  int key;
  int value;
  Node * left,  * right, * parent;
  bool isLeftChild, black;

  Node(int key, int value) {
    this -> key = key;
    this -> value = value;
    left = right = parent = NULL;
    black = false;
    isLeftChild = false;
  }
  
  void add(Node *root, int key, int value) {
    Node *node = new Node(key, value);
    if (root == NULL) {
      root = node;
      root -> black = true;
      size++;
      return;
    }
    add(root, node);
    size++; 
  }
  
  void checkColor(Node * root, Node *node) {
    if (node == root) return;
    if (!node -> black and !node -> parent -> black) {
      correctTree(node);
    }
    checkColor(root, node);
  }

  void add(Node *root, Node * node) {
    if (root -> key < node -> key) {
      if (root -> right == NULL) {
        root -> right = node;
        node -> parent = root;
        node -> isLeftChild = false;
        return;
      }
      return add(root -> right, node);
    } else {
      if (root -> left == NULL) {
        root -> left = node;
        node -> parent = root;
        node -> isLeftChild = true;
        return;
      }
      return add(root -> left, node);
    }
    checkColor(root, node);
  }
};




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  
  return 0;
} //Hajimemashite

