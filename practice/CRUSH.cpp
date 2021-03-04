
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n + 1, 0);
  for (ll &i : a) cin >> i;
  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    a[l] += k;
    a[r + 1] += -k;
  }
  ll res = a[0];
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
    res = max(res, a[i]);
  }
  cout << res << '\n';
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


