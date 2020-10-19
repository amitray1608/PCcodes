#include<iostream>
using namespace std;

void swap(int *x, int *y) {  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

void bubble_sort(int a[], int n) {
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < n-i-1; j++) {
				if(a[j] > a[j+1])
					swap(&a[j], &a[j+1]);
			}
		}
}

void insertion_sort(int a[], int n) {
	int temp;
	for(int i = 1; i<n; i++) {
		temp = a[i];
		int j = i-1;
		while(temp < a[j] && j>=0) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

void selection_sort(int a[], int n) {
	int mini;
		for(int i = 0; i<n-1; i++) {
			int mini = i;
			for(int j = i+1; j<n; j++) {
				if(a[j] < a[mini])
				mini = j;
			}
			
			swap(a[mini], a[i]);
		}
}


void merge(int a[], int l, int mid, int h)
{
		int n1 = mid-l+1;
		int n2 = h-mid;
	
		int L[n1], R[n2];
		
		for(int i = 0; i<n1; i++)
			L[i] = a[l+i];
		
		for(int i = 0; i<n2; i++)
			R[i] = a[mid+i+1];
			int i = 0, j = 0, k = l;
		while(i<n1 && j<n2)
		{
			if(L[i] <= R[j])
			{
				a[k] = L[i];
				i++;
			}
			else
			a[k] = R[j], j++;
			
			k++;
		}
		
		while(i<n1)
		{
			a[k] =L[i];
			i++;
			k++; 
		}
		
		while(j<n2)
		{
			a[k] =R[j];
			j++;
			k++; 
		}
}

void merge_sort(int a[], int l, int h)
{
	if(l<h)
	{
		int mid = (l+h)/2;
		merge_sort(a, l, mid);
		merge_sort(a, mid+1, h);
		
		merge(a, l, mid, h);
	}
}


void display(int a[], int n)
{
		for(int i = 0; i<n; i++)
			cout << a[i] << " ";
			
		cout << endl;
}

int main()
{
	int n;
	cout << "Enter the size of the array: " << endl;
	cin >> n;
	int a[n];
	cout << "Enter the number of elements of the array: "<< endl;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	cout << "Choose the type of sorting to sort the given array : " << endl;
	cout << "Enter 1 for Bubble sort: " << endl;
	cout << "Enter 2 for Insertion sort: " << endl;
	cout << "Enter 3 for Selection sort: " << endl;
	cout << "Enter 4 for Merge sort: " << endl;
	int choice;
	cin >> choice;
	switch(choice)
	{
		case 1:
			cout << "Sorted array using Bubble Sort" << endl;
			bubble_sort(a, n);
				break;
		case 2:
			cout << "Sorted array using Insertion Sort" << endl;
			insertion_sort(a, n);
				break;
		case 3:
			cout << "Sorted array using Selection Sort" << endl;
			selection_sort(a, n);
				break;
		case 4:
			cout << "Sorted array using Merge Sort" << endl;
			merge_sort(a, 0, n-1);
				break;
	}
	display(a, n);
	return 0;
}
