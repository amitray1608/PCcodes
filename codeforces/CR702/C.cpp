#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll maxn = 1e4 + 4;

unordered_map<ll, ll> cub;

void solve() {
  ll n;
  cin >> n;
  bool ok = true;
  for (ll i = 1LL; i <= maxn; i++) {
    ll x = n - (i * i * i);
    if (cub.find(x) != cub.end()) {
      cout << "YES" << '\n';
      return;
    }
  }
    cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (ll i = 1; i <= maxn; i++) {
    ll x = i * i * i;
    cub[x]++;
  }
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


