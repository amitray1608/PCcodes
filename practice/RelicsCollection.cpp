
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n + 1);
  a[0].first = a[0].second = 0;
  for (auto i = 1; i < n + 1; i++) 
    cin >> a[i].first >> a[i].second;
  vector<vector<int>> dp;
  dp.resize(n + 1, vector<int> (k + 1, 0));
  
  auto cost = [&](int i, int j) {
    int res = abs(a[i].first - a[j].first);
    res += abs(a[i].second - a[j].second); 
    return res;
  };
  
  int inf = 1e10;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++)
      dp[i][j] = inf;
  }
  for (int i = 1; i <= k; i++) 
    dp[i][i - 1] = cost(0, i);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int kk = 0; kk < min(i + 1, k); kk++) {
        dp[j][j] =  
      }
    }
  }
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


