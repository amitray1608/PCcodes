//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll maxi = LONG_MIN;
	for(ll j = n, i = 1; i <= n/2 && j >= n/2; i++, j--){
		ll x = (a*i)/b;
		x -= a*(i/b);
		maxi = max(x, maxi);
		
		x = (a*j)/b;
		x -= a*(j/b);
		maxi = max(x, maxi);
	}
	cout << maxi << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
