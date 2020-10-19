#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a)
		cin >> i;
		
	sort(a, a+n);
	ll mod = a[0];
	for(ll i = 1; i<n; i++)
	{
		mod = mod%a[i];
	}
	cout << mod << endl;
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
	
