//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl

 ll lcm(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  

void solve(){
	ll n;
	cin >> n;
	ll ans = sqrt(n);
	//deb(res);
	for(ll i = ans; i >= 1; i--){
		if(lcm(i, n/i) == n){
			cout << i << " " << n/i << endl;
			break;
		}
	}
	//cout << res << " " << n/res << endl;
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
