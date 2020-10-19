#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
	
struct Node
{
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
	
	void solve()
	{
		ll sa[101],t,s, b, count = 1, fav, i;
		cin >>s;
		for(i =0;i<s;i++) {
			cin >> sa[i];
		}
		cin >> b;
		fav = sa[b-1];
		for (i =0; i< s; i++)
		{
			if(sa[i] < fav)
				count++;
		}
		cout << count <<"\n";
}

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
