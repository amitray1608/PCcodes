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
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(e > f){
	ll ans = min(a, d)*e + min(min(b, c), (d - (min(a, d))))*f;
		cout << ans;
	}
	else{
		ll ans = min(b, min(c, d))*f + e*min(a, (d - min(b, min(d, c))));
		cout << ans;
	}
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
	
