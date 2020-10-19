//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll fun(ll a, ll k){
	ll prev = -1;
	while(--k){
		ll l = 0,s = 9; 
	   ll n = a;
		while(n) { 
			ll r = n % 10; 
			l = max(r, l); 
			s = min(r, s); 
			n = n / 10; 
		}
		a = a+(s*l);
		if(prev == a)
			break;
		prev = a;
	}
	return a;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	ll a = fun(n, k);
	cout << a << endl;
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
