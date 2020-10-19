#include<bits/stdc++.h>
using namespace std;

class Node{
		public:
			int data;
			Node * next = NULL;
};

void push(Node ** root, int data)
{
	Node * node = new Node();
	node -> data = data;
	node -> next = *root;
	*root = node;
}

void insert(Node * prev , int data)
{
	
	if(prev == NULL)
	{
		cout << "Empty Nodee\n";
		return;
	}
		Node * node = new Node();
		node -> data = data;
		node -> next = prev -> next;
		prev -> next = node; 
}

void append(Node ** root, int data)
{
		Node * node = new Node();
		Node *last = *root;
		
		node ->data = data;
		node ->next = NULL;
		
		if(*root == NULL)
		{
			*root = node;
			return;
		}
		
		while(last -> next != NULL)
		{
				last = last->next;
		}
			
			last->next = node;
			
		return;
}

void display(Node * node)
{
		while(node != NULL)
		{
			cout << node -> data << " ";
			node = node -> next;
		}
}
 

void reverse(Node ** root)
{
		if(root == NULL)
			return;
			
		Node * curr = *root, *prev = NULL, *next = NULL;
		
		while(curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		
		*root = prev;
}

void rec_rev(Node ** head)
{
		if(!head)
			return;
		rec_util(Node *, NULL, head)
	
}

rec_util(Node * curr, Node *prev, Node ** head)
{
		if(!curr -> next)
		{
			*head = curr;
			curr->next = prev;
			return;
		}
	
		Node * next = curr-> next;
		curr->next = prev;
		rec_util(next, curr, head);
}

int main()
{
		Node *head = NULL;
		push(&head, 5);
		insert(head-> next, 99);
		push(&head, 4);
		push(&head, 3);
		insert(head->next, 899);
		push(&head, 2);
		append(&head, 69);
		append(&head, 96);
		cout << "THE CREATED LINKED LIST IS :\n";
		display(head);
		//reverse(&head);
		 rec_rev(&head);
		 cout << "\nTHE  LINKED LIST afeter reverse is :\n";
		display(head);
	return 0;
}
