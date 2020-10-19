#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	int n, m;
	cin >> n >> m;
	int sum = 0;
	vector< vector<int> > v(n, vector<int>(m));
	for(auto &i : v)
	{
		for(auto &j : i)
			cin >> j, sum+=j;
	}
	
/*	
	for(auto i : v)
	{
		for(auto j : i)
			cout << j << " ";
		
		cout << endl;
	}
	*/
	// int sum = 0;
	 bool flag = false;
	 //cout << "ok" << endl;
	 for(int i= n-1; i>=0; i--)
	 {
		 for(int j = m-1; j>=0; j--)
		 {
			 
			if(v[i][j] == 0 )
			{
					v[i][j] = min(v[i+1][j]-1, v[i][j+1]-1);
								sum += v[i][j];
		
			}
				
		 }
	 } 
	 
	 for(int i = 0; i<n; i++)
	 {
			for(int j = 0; j<m; j++)
			{

				if(v[i][j] >= v[i+1][j] || v[i][j] >= v[i][j+1] )
				{	
					flag = true;
				}
	}
	 
	 
	 if(flag)
		cout << -1 << endl;
	else
	 cout << sum << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
