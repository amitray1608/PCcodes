#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	
	for(ll & i : a)
		cin >> i;
	
	//int count = 0, prev = 0;
	
	for(ll i = 0; i<k; i++)
	{
		ll x = a[i%n], y = a[n- (i%n)-1];
		deb(x);
		deb(y);
		a[i%n] = x^y;
		deb(a[i%n]);
	}
	
	for(ll i : a)
	{
		cout << i << " ";
	}
		cout << endl;
	
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
	
