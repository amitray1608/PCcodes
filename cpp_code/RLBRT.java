/*
 Define right-leaning red-black BSTs as BSTs having red and black edges satisfying the following three restrictions:
i. Red links lean right only.
ii. No node has two red links connected to it.
iii. Every path from the root to a leaf has the same black depth.
(a) Rewrite the put() method, on page 439 of the Sedgewick book , 
    so that it works for right-leaning red-black trees instead of left-leaning red-black trees.
(b) Using a construction proof, show that for every right-leaning red-black tree there is a corresponding left-leaning red-black tree.
*/


// Sedgewick book page 439 put() method implementation.
public class RedBlackBST <Key extends Comparable<Key>, Value> {
    private Node root;
    private class Node // BST node with color bit (see page 433)
    private boolean isRed(Node h) // See page 433.
    private Node rotateLeft(Node h) // See page 434.
    private Node rotateRight(Node h) // See page 434.
    private void flipColors(Node h) // See page 436.
    private int size() // See page 398.
    
    public void put(Key key, Value val) { // Search for key. Update value if found; grow table if new.
      root = put(root, key, val);
      root.color = BLACK;
    }
    
    private boolean isRed(Node x) {
      if (x == null) return false;
      return x.color == RED;
    }

    private void flipColors(Node x) {
      x.color = RED;
      x.left.color = BLACK;
      x.right.color = BLACK;
    }
    
    private Node rotateLeft(Node h) {
      Node x = h.right;
      h.right = x.left;
      x.left = h;
      x.color = h.color;
      h.color = RED;
      return x;
    }

    private Node rotateRight(Node h) {
      Node x = h.left;
      h.left = x.right;
      x.right = h;
      x.color = h.color;
      h.color = RED;
      return x;
    }

    private Node put(Node h, Key key, Value val) {
      if (h == null) // Do standard insert, with red link to parent.
      return new Node(key, val, 1, RED);
      int cmp = key.compareTo(h.key);
      if (cmp < 0) 
        h.left = put(h.left, key, val);
      else if (cmp > 0) 
        h.right = put(h.right, key, val);
      else 
        h.val = val;
      //conditions for right leaning Red Black Tree.
      if (isRed(h.right) && !isRed(h.left)) 
        h = rotateRight(h); // lean right
      if (isRed(h.left) && isRed(h.left.left)) 
        h = rotateLeft(h);
      if (isRed(h.left) && isRed(h.right)) 
        flipColors(h);
      h.N = size(h.left) + size(h.right) + 1;
    return h;
  }
}
