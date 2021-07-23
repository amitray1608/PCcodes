
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int MOD = 1e1;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, K;
    cin >> n >> K;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    auto flyod = [&](vector<vector<int>> x, vector<vector<int>> y) {
      vector<vector<int>> dp(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            dp[j][k] = (dp[j][k] + x[j][i] * y[i][k]) % MOD;
          }
        }
      }
      return dp;
    };
    vector<vector<int>> b(n, vector<int>(n, 0));
    while (K) {
      if (K & 1) {
        b = flyod(a, b);
      }
      K >>= 1;
      a = flyod(a, a);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << b[i][j] << ' ';
        res = (res + b[i][j]) % MOD;
      } cout << '\n';
    }
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite


