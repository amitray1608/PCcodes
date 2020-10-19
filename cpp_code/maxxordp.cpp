#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define MAX_ELEMENT 50

int dp[MAX_ELEMENT][MAX_ELEMENT][MAX];

int max_xor(int a[], int i, int j, int mask, int n){

	if(i >= n)
	{
		if(j == 0)
			return mask;
		else
			return 0;
	}

	if(dp[i][j][mask] != -1)
		return dp[i][j][mask];

	int ans = 0;
	
	if(j > 0)
		ans = max_xor(a, i+1, j-1, mask^a[i], n);
	
	ans = max(ans , max_xor(a, i+1, j, mask, n));

	return dp[i][j][mask] = ans;	
}

int main(){
	
	memset(dp, -1, sizeof dp);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i<n; i++)
	cin >> a[i];
	cout << max_xor(a, 0, k, 0, n) << endl;
	return 0;
}
