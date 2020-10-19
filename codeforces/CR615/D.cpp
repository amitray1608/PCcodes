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
   ll q,x;
   cin >> q >> x;
   ll pre[x];
   for(ll i = 0; i<x; i++) pre[i] = i;
   map<ll,ll> check;
   ll ans=0;
	while(q--){
           ll n;
           cin >> n;
           n = n % x;
           check[pre[n]]=1;
           pre[n] = pre[n]+x;
           while(check[ans] > 0) ans++;
           cout << ans << endl;
   }
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
	
