//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll lcm(ll a[], ll n){
		ll ans = 1;
		for(ll i = 0; i < n; i++){
			ans = (ans*a[i])/__gcd(ans, a[i]);
		}
		return ans;
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i: a) cin >> i;
	sort(a, a+n);
	cout << a[0] << endl;
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
	
