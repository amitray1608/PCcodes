#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  set<ll> st;
  map<ll, ll> mp;
  for (ll &i : a) {
    cin >> i;
    mp[i]++;
  }
  ll res = 1e9;
  for (auto x : mp) {
    st.insert(x.second);
  }
  for (auto i : st) {
    ll count = 0;
    for (auto j : mp) {
      if (j.second >= i) count += j.second - i;
      else count += j.second;
    }
    res = min(res, count);
  }
  cout << res << '\n';
}

signed main() {
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


