
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  map<int, int> mp;
  for (int &i : a) cin >> i, mp[i]++;
  for (int &i : b) cin >> i, mp[i]++;
  int ans = 0;
  for (auto i : mp) {
    if (i.second == 2) ans++;
  }
  cout << ans << '\n';
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


