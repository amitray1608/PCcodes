
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power(ll a, ll n) {
  ll p = 1;
  while (n > 0){
    if(n%2) p = p * a;

   	n >>= 1, a *= a;
  }
  return p;
}


void solve() {
  ll n, x;
  cin >> n;
  x = sqrtl(n);
  set<ll> ans;
  vector<bool> vis(x + 1, false);
  for (ll i = 2; i <= x; i++) {
    ll tmp, j = 2LL;
    while (1) {
      tmp = power(i, j);
      if (tmp > n) break;
      ans.insert(tmp);
      j++;
    }
  }
  cout << n - ans.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


