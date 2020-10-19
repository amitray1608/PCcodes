#include<bits/stdc++.h>
using namespace std;

int Max_Xor(int a[], int n, int k){
	int Max = INT_MIN;
	
	for(int i = 0; i < (1 << n); i++)
	{
		if(__builtin_popcount(i) == k){
			int cur_xor = 0;
			for(int j = 0; j < n; j++)	
			{
				if(i & (1<<j))
					cur_xor = cur_xor ^ a[j];
			}

		Max  = max(cur_xor, Max);
		}
		
	}

	return Max;
}


int main(){
	
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i<n; i++)
	cin >> a[i];
	
	int ans  = Max_Xor(a, n, k);
	cout << ans << endl;
}
