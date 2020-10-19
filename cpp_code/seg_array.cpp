#include<bits/stdc++.h>
using namespace std;

void segerate(int a[], int n)
{
		int i = 0, j = -1;
		for( i = 0; i<n; i++)	
		{
			if(~ a[i] & 1)
			{
				j++;
				swap(a[i], a[j]);
			}
		}
	
}

void segerate_while(int a[], int n)
{
		int right = n-1, left = 0;
		while(left < right)
		{
			while(~a[left]&1 && left < right)
				left++;
			
			while(a[right]&1 && left < right)
				right--;
				
			if(left < right)
			{
				swap(a[left], a[right]);
				left++;
				right--;
			}
			
		}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	//vector <int> a(n);
	for(int &i : a)
		cin >> i;
		
	//segerate(a, n);
	segerate_while(a, n);
	for(int i : a)
	{
			cout << i << " ";
	}
		return 0;
}
