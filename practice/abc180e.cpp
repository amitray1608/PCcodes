#include <bits/stdc++.h>

using namespace std;
const int inf = 1e8;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  for (auto &i : a) cin >> i[0] >> i[1] >> i[2];
  
  vector<vector<int>> dp(n, vector<int>(1 << n, inf));
  dp[0][0] = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          array<int, 3> c = a[i];
          array<int, 3> d = a[j];
          int dis = abs(d[0] - c[0]) + abs(d[1] - c[1]) + max(0, d[2] - c[2]);
          dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + dis);
        }
      }
    }
  }
//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j < (1 << n); j++) {
//      cout << dp[i][j] << ' ';
//    } cout << '\n';
//  }
  cout << dp[0][(1 << n) - 1] << "\n";
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


