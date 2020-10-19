#include<bits/stdc++.h>	
using namespace std;

struct Node{
	public:
		int data;
		Node *next;
};

void push(Node ** head_ref, int new_data)
{
		Node * new_node = new Node();
		new_node->data = new_data;
		new_node->next  = (*head_ref);
		(*head_ref) = new_node;
}

void inserAfter(Node * prev_node, int new_data)
{
	
		if(prev_node == NULL)
		{
			cout <<  "The given previous node do not exist:\n";
			return ;
		}
		
			Node * new_node = new Node();
			new_node->data = new_data;
			new_node->next = prev_node->next;
			prev_node->next = new_node;
}

void append(Node ** head_ref, int new_data)
{
		Node * new_node = new Node();
		Node * last = *head_ref;
		new_node->data = new_data;
		new_node->next = NULL;
		if(*head_ref == NULL)
		{
			*head_ref = new_node;
			return ;
		}
		
		while(last->next != NULL)
		{
				last = last->next;
		}
			
			last->next = new_node;
			
		return;
}

void print_list(Node *node){
		while(node != NULL)
		{
			cout << " " << node->data;
			node = node->next;
		}	
}

Node * create(Node * head)
{
	Node* temp = nullptr;
	Node* result;
	for(int i=0; i<5; ++i)
	{
		cout << "Enter an element:\n";
		int x;
		cin >> x;
		result = new Node;
		result->data = x;
		result->next = temp;
		temp = result;
	}
	return result;	
}

int main(){
	
		Node* head = NULL;
			append(&head, 6);
			push(&head, 7);
			push(&head, 1);
			append(&head, 4);
			create(head, )
			inserAfter(head->next, 8);
			head = create(head);
			cout << "Created Linked list  : ";
			print_list(head);
			
			return 0;
}


















