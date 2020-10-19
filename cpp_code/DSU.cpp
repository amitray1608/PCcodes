#include<bits/stdc++.h>
using namespace std;

void initialize(int a[], int n){
	for(int i = 0; i < n; i++)
		a[i] = i;
}
//returns true if A and B have the same parents 
bool find(int a[], int A, int B){
	if(a[A] == a[B])
		return true;
	else 
		return false;
}

void union(int a[], int A, int B){
	int t = a[A];
	for(int i = 0; i < n; i++){
		if(a[i] == t)
			a[i] = a[B];
	}
}
int main(){
	 
	return 0;
}
