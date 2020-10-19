#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void post_order(struct Node *node)
{
	if(node == NULL)
		return;

	post_order(node->left);
	post_order(node->right);
	cout << node->data << " ";
}

void pre_order(struct Node *node)
{
	if(node == NULL)
		return;

	cout << node->data << " ";
	pre_order(node->left);
	pre_order(node->right);
}

void in_order(struct Node *node){
	
	if(node == NULL)
		return;

	in_order(node->left);
	cout << node->data << " ";
	in_order(node->right);

}

oiutyu;oiuioiuty


int main()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "Pre order traverse :" << endl;

	pre_order(root);
	
	cout << "\nPost order traverse :" << endl;

	post_order(root);

	cout << "\nIn order traverse :" << endl;

	in_order(root);
}
