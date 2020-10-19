#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n], sum = 0;
	for(int i = 0; i<n; i++)
	cin >> a[i], sum+=a[i];
	int count = 0;
	int mid = (n-1)/2, sum2 = 0;	
	for(int i = 0; i<=mid; i++)
		sum2 + = a[i];
cout << abs(sum2 - sum) << endl;
}
