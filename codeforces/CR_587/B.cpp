#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	ll n;
	cin >> n;
	ll a[n], aa[n], c = 0;
	priority_queue <ll> p;
	for(ll &i :a)
		{cin >> i, aa[c++] = i,  p.push(i);
	}
	ll d = 0;
		vector<ll > v(n);
	while(!p.empty())
	{
		ll x = p.top();
		p.pop();
		for(ll i = 0; i<n; i++)
		{
			if(a[i] == x)
			v[d] = i+1, a[i] = -1;
		}
	}
	
	  sort(aa, aa+n);
	ll ans = n;
	for(ll i=n-1; i >=0 ; i--) {
		ans = ans + aa[i]*(n-1-i);

		}
		cout << ans << endl;
	for(ll i = 0; i<n; i++)
		cout << v[i] << " ";
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
	
