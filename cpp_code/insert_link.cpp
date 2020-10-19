#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;

	Node *next;	
};


Node * push(Node * root, int data){
		
		Node *node = new Node();
		node -> data = data;
		node -> next = root;
		root = node ;
		return root;
}

Node * insert(Node * root , int data)
{
		if(root == NULL)
		{
			cout << "EMPTY ROOT\n";
			return root;
		}
		
		Nod 
}


void display(Node * root)
{
		while(root != NULL)
		{
			cout << root -> data << " ";
				root = root -> next; 
		}
}

int main()
{
	Node *root = new Node();
	root = push(root, 3);
	root = push(root, 2);
	root = push(root, 1);
	display(root);
	return 0;
}
