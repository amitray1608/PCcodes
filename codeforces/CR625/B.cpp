//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	ll n;
	cin >> n;
	ll a[n];
    for(ll &i : a) cin >> i;
	unordered_map<ll, ll> check;
	ll byfar[n] = {0};
    ll curr = 0, maxi = 0;
	for(ll i = 0; i < n; i++) {
		ll dist = a[i] - i;
		if(check.find(dist) == check.end()) {
			byfar[i] = a[i];
			check[dist] = i;
		}
		else {
			byfar[i] = a[i] + byfar[check[dist]];
			check[dist] = i;
		}
	}
	for(ll i = 0; i < n; i++) 
		maxi = max(maxi, byfar[i]);

	cout << maxi << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
