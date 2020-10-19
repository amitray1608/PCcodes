#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

void push(Node ** head_ref, int new_data) {
	Node * node = new Node();
	node->data = new_data;
	node->next = (*head_ref);
	(*head_ref) = node;
}

void inserAfter(Node * prev_node, int new_data) {
	if(prev_node == NULL) {
		cout << "Empty node\n";
		return;
	}

	Node * node = new Node();
	node->data = new_data;
	node->next = prev_node->next;
	prev_node = node;

}

void append(Node ** head_ref, int new_data) {
	Node *node = new Node();
	Node *last =  *head_ref;
	node->data = new_data;
	if(*head_ref == NULL) {
		*head_ref = node;
		return;
	}
	
	while(last->next != NULL)
		last = last->next;
		
		last->next = node;
			
	return;
}

void print(Node *head) {
	while(head != NULL) {
		cout << " " << head->data;
		head = head->next;
	}
}

int main() {
		Node *head = NULL;
		append(&head, 6);
		push(&head, 7);
		append(&head, 88);
		push(&head, 77);
		append(&head, 99);
		inserAfter(head->next , 69);
		cout << "Current linked list : ";
		print(head);
		cout << endl;
		return 0;
}

















