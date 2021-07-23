
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int MOD = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, K;
  cin >> n >> K;
  cout << MOD << '\n';
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
          dp[j][k] = (dp[j][k] + (x[j][i] * y[i][k]) % MOD) % MOD;
        }
      }
    }
    return dp;
  };
  vector<vector<int>> b(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) b[i][i] = 1;
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
      res = (res + b[i][j]) % MOD;
    } cout << '\n';
  }
  cout << res << '\n';
  return 0;
} //Hajimemashite


