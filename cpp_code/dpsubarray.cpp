#include<bits/stdc++.h>
using namespace std;

bool subarray(int a[], int n, int sum){
	
	bool subset[n+1][sum+1];
	
	for(int i = 0; i<n; i++)
		subset[i][0] = true;
	
	for(int i = 0; i<sum; i++)
		subset[0][i] = false;
	
	
	for(int i = 0; i<n; i++)
	{	
		for(int j = 0; j<sum; j++)
		{
			if(j<a[i-1])
				subset[i][j] = subset[i-1][j];
			if(j >= a[i-1])
				subset[i][j] = subset[i-1][j] || subset[i-1][j - a[i-1]];
		}
	}
		for(int i = 0; i<=n; i++)
		{	for(int j = 0; j<=sum; j++)
				cout << subset[i][j] << " ";
		cout << endl;
		}
	
return subset[n] [sum];

}

int main()
{
	int n, sum = 0;
	cin >> n >> sum ;
	int a[n]; 
	for(int i = 0; i<n; i++)
		cin >> a[i];

	(subarray(a, n, sum)) ? cout << "Found it " :  cout << "Not found";

return 0;
}
