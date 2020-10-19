//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 5e5 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ' ';
  return res;
}
 
template<class A> void vbug(A x) {
  cout << to_string(x) << endl;
}

vector<ll> fac, ifac;

ll mpow2(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return ans;
}

ll modInverse(ll n)  { 
  return mpow2(n, MOD - 2); 
} 

ll comb(ll n, ll k){
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
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

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll>f;
  for(ll &i : a)
    cin >> i, f[i]++;
  
  vector<ll>pre(n+1, 1);
  vector<ll>suf(n+2, 1);

  for(auto i : f) {
    ll calc = 1;
    for(ll ii = 1; ii <= i.second; ii++) {
      calc = (comb(i.second, ii) + calc) % MOD;
      pre[ii] = (calc * pre[ii]) % MOD;
    }
    suf[i.second+1] = (calc * suf[i.second+1]) %MOD;
  }
  vbug(pre);
  vbug(suf);
  ll mul = 1;
  for(ll i = 1; i <= n; i++) {
    mul = (mul * suf[i])%MOD;
    pre[i] = (pre[i]*mul)%MOD;
  }
  vbug(pre);
  vector<ll>anss(n+1, 0);

  for(ll i = 1; i <= n; i++) {
    ll ans, ans1, total;
    ans = 0;
    total = 1;
    for(int j = 1; j <= f[i]; j++) {
      ll var; 
      ans1 = comb(f[i], j);
      var = ans1;
      // deb(ans1);
      total = (total + var) % MOD;

      pre[j] = (pre[j] * modInverse(total))%MOD;
      ans1 = (pre[j] * ans1) %MOD;
      // deb(ans1);
      vbug(pre);
      pre[j] = (pre[j] * (total - var + MOD)%MOD) %MOD;
      ans = (ans + ans1) %MOD;
      // deb(ans);
    }
    anss[i] = ans;
  }


  for(ll i = 1; i < n+1; i++)
    cout << anss[i] << ' ';
  cout << endl; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  setcomb();
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
1
6
1 1 2 2 2 3

1
4
1 2 2 3

1
3
2 2 3
2
1 2
3
1 2 2
*/