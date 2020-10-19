//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int mod = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll power(ll base, ll exp){
	ll res = 1;
	while(exp > 0){
		if(exp&1) res = (res * base)%MOD;
		base = (base*base)%MOD;
		exp >>= 1;
	}
	return res;
}
 
int invmod(int n, int p) {
  int ans = n % MOD;
  ans *= power(p, MOD - 2);
  ans %= MOD;
  return ans; 
}
int nCr(int n, int r) {
  int mn;
  mn = min(r, n - r);
  int pr = 1;
  int nn = n;
  for (int i = 1; i <= mn; i++) {
    pr *= nn;
    pr %= mod;
    nn--;
  }
  for (int i = 1; i <= mn; i++) {
    pr = invmod(pr, i);
  }
  return pr;
}
void solve(){
	//auto nCr = [&](ll n, ll r){
	  //int mn;
	  //mn = min(r, n - r);
	  //ll pr = 1;
	  //ll nn = n;
	  //for (int i = 1; i <= mn; i++) {
		//pr *= nn;
		//pr %= MOD;
		//nn--;
	  //}
	  //for (int i = 1; i <= mn; i++) {
		//pr = invmod(pr, i);
	  //}
	  //return pr;
	//};
	  int n, a, b;
	  cin >> n >> a >> b;
	  ll ans = (power(2, n) - 1 + mod ) % mod;
	  ans -= nCr(n, a);
	  ans = (ans + mod) % mod;
	  ans -= nCr(n, b);
	  ans = (ans + mod) % mod;
	  cout << ans << endl;
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
