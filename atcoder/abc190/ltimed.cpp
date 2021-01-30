
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll &i : a) cin >> i;
  ll gcd = 0;
  for (int i = 0; i < n; i++) {
    gcd = __gcd(gcd, a[i]);
  }
  while(k % 2 == 0) k >>= 1;
  bool ok = (gcd % k == 0);
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


