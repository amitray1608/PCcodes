#include<bits/stdc++.h>
using namespace std;


int partition(int *a, int l, int h)
{
		int pIndex = l;
		int pivot = a[h];
		for(int i = l; i<h; i++)
		{
			if(a[i] <= pivot)
			{
				swap(a[i], a[pIndex]);
				pIndex++;
			}
		}
		
		swap(a[pIndex], a[h]);
	
	return pIndex;
	
}

void quicksort(int *a, int l, int h)
{
		if(l<h)
		{
			int p = partition(a, l, h);
			quicksort(a, l, p-1);
			quicksort(a, p+1, h);
		}
}

int main(){
	int n;
	cout << "Enter the size of the array: \n";
	cin >> n;
	int a[n];
	cout << "Enter the elements of the array:\n";
	for(int i = 0; i<n; i++)
		cin >> a[i];

	quicksort(a, 0, n-1);
cout << "After Sorting:\n";
	for(int i = 0; i<n; i++)
	cout << a[i] << " ";

cout << endl;
}






















