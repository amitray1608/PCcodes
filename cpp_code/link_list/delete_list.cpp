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
 
void deleteNode(Node ** head, int key)
{
		Node * temp = * head, *prev;
		
		if(temp != NULL && temp -> data == key)
		{
			*head = temp -> next;
			free(temp);
			return;
		}
		
		while(temp != NULL && temp -> data != key)
		{
			prev = temp;
			temp = temp -> next;
			
		}
		
		if(temp == NULL) 
		{
				return;
		}
			prev -> next = temp -> next;
			free(temp);
}


void deleteNode(Node ** root, int key)
{
	Node * temp = *root, prev;
	if(temp != NULL && temp -> data == key)
	{
		*root = temp-> next;
		free(root);
		return;
	}
	
	while(temp != NULL && temp -> data != key)
	{
		prev = temp;
		temp = temp -> next;
	}
	if(temp == NULL)
	{
		return;
	}
	
	prev -> next = temp -> next;
	
	free(temp);
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
		deleteNode(&head, 899);
		deleteNode(&head, 5);
		 cout << "\nTHE  LINKED LIST afeter deletion is :\n";
		display(head);
	return 0;
}
