#include<bits/stdc++.h>
using namespace std;

int findPeakUtil(int arr[], int low, int high, int n) 
{ 
 
    int mid = low + (high - low)/2;  
  
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == n-1 || arr[mid+1] <= arr[mid])) 
        return mid; 
 
    else if (mid > 0 && arr[mid-1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid -1), n); 
 
    else return findPeakUtil(arr, (mid + 1), high, n); 
} 
  
int findPeak(int arr[], int n) 
{ 
    return findPeakUtil(arr, 0, n-1, n); 
} 

bool ispeak(int a[], int l, int h){
		if(l>h)
			return false;
		
		int mid = (l+h)/2;
		
		if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
			return true;
		else if(a[mid+1] > a[mid])
			return ispeak(a, mid+1, h);
		else
			return ispeak(a, l, mid);
		
}

int main(){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i<n; i++)
			cin >> a[i];
			int x = findPeak(a, n);
		cout << x << endl;
		
	return 0;
}
