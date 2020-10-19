 #include<bits/stdc++.h>
using namespace std;
int siz = 10;
int queu[10];
int front = -1, rear = -1, top = 0;
int n=10;
	void push_back(int data){
		if(rear == n)
			cout << "Overflow\n";
		else
			queu[++rear] = data;
	}

	void deleteQ(){
		if(front == rear)
		cout << "Underflow\n";
		else
		cout << "Element deleted is : " << queu[front+1] << endl, front++;
	}

	void printQ()
	{
		cout << "Elements are : \n";
		int a = front+1, b = rear;

		while(a<=b)
		{
			cout << queu[a++] << " ";
		}
		cout << endl;
	}

//circular

int cqueue[10];
int frontq = -1, rearq = -1;

	void insertCQ(int val) {
		if ((frontq == 0 && rearq == n-1) || (frontq == rearq+1)) {
		cout<<"Overflow \n";
		return;
	}
	if (frontq == -1) {
		frontq = 0;
	rearq = 0;
	}else {
		if (rearq == n - 1)
			rearq = 0;
		else
			rearq = rearq + 1;
	}
	cqueue[rearq] = val ;
	}
	void deleteCQ() {
		if (frontq == -1) {
		cout << "Underflow\n";
		return;
	}
	cout << "Element deleted from queue is : "<<cqueue[frontq]<<endl;

	if (frontq == rearq) {
		frontq = -1;
		rearq = -1;
	} else {
	if (frontq == n - 1)
		frontq = 0;
	else
		frontq = frontq + 1;
	}
	}
	void displayCQ() {
		int f = frontq, r = rearq;
		if (frontq == -1) {
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Queue elements are :\n";
	if (f <= r) {
	while (f <= r){
		cout<<cqueue[f]<<" ";
		f++;
	}
	} else {
	while (f <= n - 1) {
		cout<<cqueue[f]<<" ";
		f++;
	}
	f = 0;
	while (f <= r) {
		cout<<cqueue[f]<<" ";
		f++;
	}
	}
	cout<<endl;
}

	int main()
	{
		cout << "Enter 1 for Queue data structure:\n";
	cout << "Enter 2 for Circular Queue data structure:\n";

	int x;
	cin >> x;

	if(x == 1)
	{
		cout << "You chose Queue:\n";
		cout << "Enter 1 to insert element.\n";
		cout << "Enter 2 to delete element.\n";
		cout << "Enter 3 to display Queue.\n";
		cout << "Enter 4 to exit.\n";
		int ch;
		do {
		cout<<"Enter choice : "<<endl;
		cin >> ch;
		switch(ch)
		{
		case 1:
			int val;
			cout<<"Input for insertion: "<<endl;
			cin >> val;
			push_back(val);
			break;

		case 2:
			deleteQ();
			break;

		case 3:
			printQ();
			break;

		case 4:
			cout<<"Exit\n";
			break;
		default: 
			cout<<"Incorrect!\n";
		}
	} while(ch != 4);
	}
	
	else{
			cout << "You chose Circular queue:\n";

			int ch, val;
			cout << "Enter 1 to insert element.\n";
			cout << "Enter 2 to delete element.\n";
			cout << "Enter 3 to display Queue.\n";
			cout << "Enter 4 to exit.\n";
			do {
			cout<<"Enter choice : "<<endl;
			cin>>ch;
			switch(ch) {
			case 1:
				cout<<"Input for insertion: "<<endl;
				cin>>val;
				insertCQ(val);
				break;

			case 2:
				deleteCQ();
				break;

			case 3:
				displayCQ();
				break;

			case 4:
				cout<<"Exit\n";
				break;
				default: cout<<"Incorrect!\n";
			}
		} while(ch != 4);
}

return 0;
}
