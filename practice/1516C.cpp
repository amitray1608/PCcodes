
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  int s = accumulate(a.begin(), a.end(), 0);
  int maxi = 1e9;
  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, 0));
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= s; j++) {
      dp[i][j] = dp[i - 1][j];
      if (a[i - 1] <= j)
        dp[i][j] = dp[i][j] | dp[i - 1][j - a[i - 1]];
    }
  }
  int half = (s >> 1);
  for (int i = half; i >= 0; i--) {
    if (dp[n][i]) {
      maxi = s - (i << 1);
      break;
    }
  }
  bool ok = (maxi > 0);
  array<int, 2> res;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1 or !dp[n][(s >> 1) - (a[i] >> 1)]) {
      res[0] = 1;
      res[1] = i + 1;
      break;
    }
  }
  if (ok) {
    cout << 0 << '\n';
  } else {
    cout << res[0] << '\n';
    cout << res[1] << '\n';
  }
  return 0;
} //Hajimemashite

