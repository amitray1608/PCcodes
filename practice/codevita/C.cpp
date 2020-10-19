#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e3 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<ll>fac, ifac; 

ll mpow2(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return ans;
}

ll comb(ll n, ll k){
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void setcomb() {
  fac.resize(siz);
  ifac.resize(siz);
  fac[0] = ifac[0] = 1LL;
  for (ll i = 1; i < siz; i++) {
    fac[i] = (fac[i-1] * i) % MOD; 
  }
  ifac[siz-1] = mpow2(fac[siz-1], MOD - 2LL);
  for (ll i = siz-2; i >= 0; i--) {
    ifac[i] = 1LL * ifac[i+1] * (i+1) % MOD;
  }
}


void solve() {
  ll l, r, k;
  cin >> l >> r >> k;
  ll even, odd;
  even = (r-1+1)/2;
  odd = (r-l+1) - even;
  vector<vector<ll>> pref(k+1, vector<ll> (2, 0));   
  pref[1][0] = even, pref[1][1] = odd;
  for(int i = 2; i <= k; i++){
    pref[i][0] = (((pref[i-1][0]%MOD)*(even%MOD))%MOD + ((pref[i-1][1]%MOD)*(odd%MOD))%MOD)%MOD;
    pref[i][1] = (((pref[i-1][0]%MOD)*(odd%MOD))%MOD + ((pref[i-1][1]%MOD)*(even%MOD))%MOD)%MOD;
  }
  
  cout << pref[k][0]%MOD << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  setcomb();
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  