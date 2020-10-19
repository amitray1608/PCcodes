#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	int n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	for(ll &i : a)
		cin >> i, sum += i;
		
	ll ans = (sum/n);
	if(sum % n) ans++;
	cout << ans << endl;
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
	
