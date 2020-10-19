//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll binpows(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
	
void solve(){
	ll l, r;
    cin >> l >> r;
	ll ans = 0;
	for(int i = 0; i < 60; i++){
		if(l>>i&1^1)
			continue;
		ll l2 = min((l>>i)+1<<i, r+1);
		ans += ((l2-l)%MOD)*((1LL<<i)%MOD)%MOD;
	}
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "b", stdin);
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
	
	/* 
5
47 98
32 66
765 999
234 1000
34 87
559
1024
121077
4980
964
*/
