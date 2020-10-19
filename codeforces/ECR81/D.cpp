//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll phi_f(ll n){
	float result = n;
	for(ll p = 2; p*p <= n; p++){
		if(n%p == 0){
			while(n%p == 0) n /= p;
				result *= (1.0 - (1.0/(float)p));
		}
	}
	if(n > 1)
		result *= (1.0 - (1.0 / (float)n));
		
	return (ll) result;
}

ll phi_i(ll n){
	ll result = n;
	for(ll p = 2; p*p <= n; ++p){
		if(n%p == 0){
			while(n%p == 0)	n/=p;
			
			result -= result/p;
		}
	}
	if(n > 1)
		result -= result/n;
		
	return result;
}

void solve(){
		ll a, m;
		cin >> a >> m;
		ll x = m/__gcd(a, m);
        ll ans = phi_i(x); 
		cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
