#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define int long long
#define ll long long
typedef long double ld;
const int MOD = 1e9 + 7;
const int siz = 2e5 + 1;

vector<int> fac(siz), ifac(siz);

ll mpow2(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return ans;
}

long long MODinv(long long a) {
	long long b = MOD, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}
void setcomb() {
  fac.resize(siz);
  ifac.resize(siz);
  fac[0] = 1LL;
  ifac[0] = 1LL;
  for (ll i = 1; i < siz; i++) {
    fac[i] = (fac[i-1] * i) % MOD;
  }
  ifac[siz-1] = mpow2(fac[siz-1], MOD - 2LL);
  for (ll i = siz-2; i >= 0; i--) {
    ifac[i] = 1LL * ifac[i+1] * (i+1) % MOD;
  }
}

//ll comb(ll a, ll b) {
//	if (a == 0 && b == 0)return 1;
//	if (a < b || a < 0)return 0;
//	ll tmp = ifac[a - b] * ifac[b] % M;
//	return tmp * fac[a] % M;
//}
//ll perm(ll a, ll b) {
//	if (a == 0 && b == 0)return 1;
//	if (a < b || a < 0)return 0;
//	return fac[a] * ifac[a - b] % M;
//}

int nChoosek(int n, int k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for(int i = 2; i <= k; ++i ) {
        result = (result * (n-i+1)) % MOD;
        result = (result * MODinv(i)) % MOD;
    }
    return result;
}


void solve() {
  int n, m, k, total = 0;
  cin >> n >> m >> k;
  vector<int> v(n);
  for(int &i : v) cin >> i;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) {
    int tmp = v[i] + k;
    auto p = upper_bound(v.begin(), v.end(), tmp); p--;
    int x = p - v.begin() - i;
    if(*p <= tmp) {
      total = (total + nChoosek(x, m - 1LL)) % MOD;
    }
  }
  cout << total << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
