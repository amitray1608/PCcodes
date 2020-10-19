#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	ll n, m, q;
	cin >> n >> m >> q;
	vector < vector<ll> > v(n+1, vector<ll> (m+1, 0));
	long count = 0;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		for(ll i = 1; i<=n; i++)
			v[i][y] += 1;
		
		for(ll j = 1; j<=m; j++)
			{v[x][j] += 1;}	
	}
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(v[i][j] & 1)
				count++;
		}
	}
	cout << count << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
