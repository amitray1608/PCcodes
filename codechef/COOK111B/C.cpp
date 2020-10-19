//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;

ll quer(ll l, ll r){
	//int pos = l, prev = 0, xo = 0;
	ll bit =0;
	while(r>0){
		bit++;
		r/=2;
	}
	cout << bit << endl;
	ll ans= 0;
	for(ll i = bit-1; i >= 0; i--) ans += pow(2, i);
		
	return ans;
}
void solve()
{
	ll l, r;
	cin >> l >> r;
	ll ans = quer(l, r);
	//ll ans = stoll(s, 0, 2); 
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
	
