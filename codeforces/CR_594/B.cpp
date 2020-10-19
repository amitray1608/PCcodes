//“Make it work, make it right, make it fast.” – Kent Beck
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
    cin>>n;
    vector<ll> a(n);
	for(ll i = 0; i<n; i++)    cin>>a[i];

	sort(a.begin(), a.end()); 
	
	ll tmp=0, tmp2=0;
	for(ll i=0; i<n/2; i++)
	{
		tmp += a[i];
		tmp2 += a[n-1-i];
	}
	if(n&1)
		tmp2 += a[n/2];
	
    ll ans = (tmp*tmp)+(tmp2*tmp2);
	cout << ans << endl;
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
	
