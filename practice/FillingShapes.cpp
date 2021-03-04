
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << 0 << '\n';
    return;
  }
  vector<long long> dp(n / 2, 0);
  dp[0] = 2;
  for (int i = 1; i < n / 2; i++) {
    dp[i] = 2LL * dp[i - 1];
  }
  cout << dp[n / 2 - 1] << '\n';
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


