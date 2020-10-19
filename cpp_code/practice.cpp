#include<bits/stdc++.h>
using namespace std;

void bb(int a[], int n){
		for(int i = 0; i<n; i++){
			for(int j = i; j <n-i-1; j++)
				if(a[j] > a[j+1]) swap(a[j], a[j+1]);
		}
}

void ins(int a[], int n){
	for(int i = 1; i<n; i++){
		int j = i-1;
		int t = a[i];
		while( t < a[j] && j >= 0)
			a[j+1] = a[j], j--;
			
		a[j+1] = t;
	}
	
}

void sel(int a[], int n){
	for(int i = 0; i < n-1; i++){
		int m = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[m])
				m = j;
		}
		swap(a[i], a[m]);
	}
}

void merge(int a[], int l, int mid, int h){
	int n1 = mid-l+1;
	int n2 = h-mid;
	
	int L[n1], R[n2];
	
	for(int i = 0; i<n1; i++)
		L[i] = a[l+i];
	for(int i = 0; i<n2; i++)
		R[i] = a[mid+i+1];
		
	int i = 0, j = 0, k = l;
	
	while(i < n1 && j < n2){
		if(L[i] < R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}
	while(i < n1)
		a[k++] = L[i++];
		
	while(j < n2)
		a[k++] = R[j++];
	 
}


void mergS(int a[], int l, int h){
	if(l < h){
		int mid = (h+l)/2;
		mergS(a, l, mid);
		mergS(a, mid+1, h);
		merge(a, l, mid, h);
	}
}

int part(int a[], int l, int h){
	int pv = a[h];
	int pos = l;
	for(int i = l; i <h; i++){
		if(a[i] <= pv){
				swap(a[i], a[pos++]);
		}
	}
	swap(a[pos], a[h]);
return pos	;
}

void Quik(int a[], int l, int h){
	if(l < h){
		int p = part(a, l, h);
		Quik(a, l, p-1);
		Quik(a, p+1, h);
	}
}
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
int binaryS(int a[], int l, int h, int k){
	if(l<=h){
		int mid = (l+h)/2;
		if(k == a[mid]) return mid;
		if(k < a[mid])
			return  binaryS(a, l, mid-1, k);
		else 
			return binaryS(a, mid+1, h, k);
	}
	return -1;
}

int main(){
	int n = 5;
	int a[5] = {9, 2, 8, 3, 7};
	Quik(a, 0, n-1);
	for(int i : a) cout << i << " ";
	cout << endl;
	cout<<binarySearch(a, 0, n-1, 9) << endl;
	return 0;
}
