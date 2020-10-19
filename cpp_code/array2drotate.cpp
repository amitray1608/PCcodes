//RAY COMPETATIVE CODING TEMPLATE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e+7;
int main(){
	
	int n;
	cin >> n;
	int a[n][n];
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin >> a[i][j];
			
		int b[n][n];
		int aa=0, bb=n-1;
		for(int i = 0; i<n; i++)
			{
				for(int j = 0; j<n; j++)
					b[j][bb] = a[aa][j];
					
				aa++, bb--; 
			}
			
			cout << "\nAfter rotating the array :\n";
			
			for(int i = 0; i<n; i++)
			{
				for(int j = 0; j<n; j++)
					cout << b[i][j] << " ";
					
					cout << endl;
			}
			
	
	return 0;	
}
