//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	ll n;
	cin >> n;
	vector<ll>v(n);
	
	for(ll &i : v) cin >> i;
	
	sort(v.begin(), v.end());

	ll q;
	cin >> q;
	while(q--){
		ll m;
		cin >> m;
		ll pos = upper_bound(v.begin(), v.end(), m) - v.begin();
		cout << pos << endl;
	}	
}

int main()
{
	#ifndef RAY
		freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
