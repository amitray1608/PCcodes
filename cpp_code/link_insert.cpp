#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node * next;
};

void push(Node ** root, int data)
{
		Node *node = new Node();
		node -> data = data;
		node -> next = *root;
		*root = node;  
}

void insert(Node * prev, int data)
{
		if(prev == NULL)
		{
			cout << "The given previous node is NULL\n";
			return;
		}
		
		Node * node = new Node();
		node -> data = data;
		node -> next = prev->next;
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
			{last = last->next;
		}
			last->next = node;
			
		return;
}

void printlist(Node *node)
{
		while(node != NULL)
		{
			cout << " " << node -> data;
			node = node->next;
		}
}


int main()  
{  
    Node* head = NULL;  
      
    append(&head, 6);  

    push(&head, 7);  

    push(&head, 1);  

    append(&head, 4);  

    insert(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    printlist(head);  
      
    return 0;  
}  
