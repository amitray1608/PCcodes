#include<bits/stdc++.h>
using namespace std;
void binary(int a[], int l, int h, int key)
{
	int m;
	while(l<=h){
	m = (h+l)/2;
	if(a[m] == key)
	{
		cout << "Found at : " << m << endl;
		break;		
	}
	else if(a[m]<key)
		l = m+1;
	else
		h = m-1;
	}
	if(l>h)
	cout << "Element not found:\n";
}

void linear(int a[], int n, int val){

	int i;
	for(i = 0; i<n; i++)
	{
		if(a[i]==val)
		{
			cout << "Found at "<< i << endl;
			break;
		}	
	}

	if(i==n)
		cout << "Element not found:\n";

}

int main(){
	
	cout << "Enter the size of the array:\n";
	int n;
	cin >> n;
	int a[n];		
	cout << "Enter the elements of the array:\n";
	for(int i = 0; i<n; i++)
		cin >> a[i];
	cout << "Enter the value to be searched:\n";
	int key;
	cin >> key;
	cout << "Through linear Search:\n";
	linear(a, n, key);
	cout << "Through binary Search:\n";
	binary(a, 0, n-1, key);
return 0;
}
