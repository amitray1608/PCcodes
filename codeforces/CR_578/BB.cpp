#include<bits/stdc++.h>
using namespace std;

void solve()
{
		int n, m, k;
		cin >> n >> m >> k;
		int a[n];
		for(int i = 0; i<n; i++)
			cin >> a[i];
			
		bool flag = true;
		
		for(int i = 0; i<n-1; i++)
		{
			int least = max(0, a[i+1]-k);
			m += a[i] - least;
			if(m<0)
			{
				flag = false;
				break;
			}
		}
		
		(flag) ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
