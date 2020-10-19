#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
void printlist(Node* n)
{
		while(n != NULL)
		{
			cout << n->data << " ";
			n = n->next;
		}
}



int main()
{
		Node *head = new Node();
		Node *a = new Node();
		Node *b = new Node();

		head->data = 1;
		head->next = a;
		a->data = 2;
		a->next = b;
		b->data = 3;
		b->next = NULL;
		printlist(head);
}
