//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll binpow(ll a, ll b) {
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
	ll a, b, log_val, twice;
    cin >> a >> b;
     log_val =  log2(a);
     twice = binpow(2, log_val);
    ll total = twice, count, sount;
    ll x = (2*twice)-1;
    if(x < b)
        count = x;
    else
        count = b;

    if(a > twice)
        sount = twice;
    else    
        sount = a;
 
    total *= (count-sount+1);
    cout << total << endl;
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
	
