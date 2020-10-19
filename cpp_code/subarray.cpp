#include<bits/stdc++.h>
using namespace std;

bool issubset(int a[], int n, int sum){
	if(sum == 0)
		return true;
	if(n == 0 && sum != 0)
	return false;

	if(a[n-1]>sum)
		return issubset(a, n-1, sum);

	return issubset (a, n-1, sum) || issubset(a, n-1, sum-a[n-1]);
}


int main(){
	int n, sum = 0;
	cin >> n >> sum;
	int a[n];
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	(issubset(a, n, sum)) ? cout << "Found it!! " : cout << "Not found";
	
return 0;
}
