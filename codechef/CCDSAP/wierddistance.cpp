//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int siz = 1e8+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll n;
	cin >> n;
	ll a[n], b[n], prea[n], preb [n];
	for(ll &i : a) cin >> i;
	for(ll &i : b) cin >> i;
	prea[0] = a[0], preb[0] = b[0];
	for(ll i = 1; i < n; i++)
		prea[i] = prea[i-1]+a[i], preb[i] = preb[i-1]+b[i];
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		if(prea[i] == preb[i] && a[i] == b[i]){
			ans += a[i];
		}
	}
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
