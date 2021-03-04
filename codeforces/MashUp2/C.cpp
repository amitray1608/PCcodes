#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  set<int> st;
  for (auto i : a) {
    cin >> i.first >> i.second;
    st.insert(i.first);
    st.insert(i.second);
  }
  map<int, int> mp;
  int val = 1;
  for (int i : st) {
    mp[i] = val++;
  }
  vector<int> pre(val + 1, 0);
  for (auto i : a) {
    int newx = mp[i.first], newy = mp[i.second];
    pre[newx] += 1;
    pre[newy] += 1;
  }
  for (int i = 1; i < val + 1; i++) {
    pre[i] += pre[i - 1];
  }
  vector<int> res(val + 1, 0);
  for (int i = 0; i < n; i++) {
    int newx = mp[a[i].first], newy = mp[a[i].second];

    int ans = pre[newy] - pre[newx - 1];
    cout << ans << endl;
  }
}

signed main() {
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


