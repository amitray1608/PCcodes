
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, h, v;
  cin >> n >> h >> v;
  vector<ll> a(n);
  for (ll &i : a) cin >> i;
  ll cost = 0;
//  if (a[n - 1] == a[n - 2])
//    cost += h + v;
//  else 
//    cost += min(h, v);
  bool gap = false;
  bool bet = false;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) gap = true;
    if (abs(a[i] - a[i + 1]) >= 2) bet = true;
    if (bet) break;
  }
  if (!gap) {
    cost = min(2LL * v, h + v);
  } else if (bet == true) {
    cost = 0;
  } else {
    cost = min(h, v);
  }
  cout << cost << '\n';
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


