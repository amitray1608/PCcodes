#include<bits/stdc++.h>
using namespace std;

int query(int BIT[], int indx){
		int sum = 0;
		while(indx > 0){
			sum += BIT[indx];
			indx -= indx&-indx;
		}
	return sum;
}

void update(int BIT[], int n, int indx, int val){
		
		while(indx <= n){
				BIT[indx] += val;
				indx += indx & (-indx);
		}
}

int getInvCount(int a[], int n){
		
		int invcount = 0;
		
		int maxi = *max_element(a, a+n);
		//cout << maxi << endl;
		int BIT[maxi+1] = {0};
	//cout << BIT[maxi] << endl;
		for(int i = n-1; i>=0; i--){
				invcount += query(BIT, a[i] - 1);
				update(BIT, maxi, a[i], i);
		}
	return invcount;
}

int main(){
	
	int n;
	cin >> n;
	int a[n];
	for(int &i : a)	
	{	cin >> i;
	}
		for(int i : a){
		
		cout << i << " ";
	}
		cout << endl;
	int count = getInvCount(a, n);
	cout << count << endl;	
	return 0;
}
