
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector<pair<int, int>> v;
  for (int i : {1, n})
    for (int j : {1, m})
      v.push_back({i, j});
  
  int ans = 0;
  for (auto i : v) {
    ans = max(ans, abs(i.first - r) + abs(i.second - c));
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


