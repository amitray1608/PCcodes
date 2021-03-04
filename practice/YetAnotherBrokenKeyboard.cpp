
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int avail[26] = {0};
  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    int ind = c - 'a';
    avail[ind] = 1;
  }
  vector<long long> dp(n, 0);
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    if (avail[ind]) {
      dp[i] = 1;
    }
  }
  long long ans = dp[0];
  for (int i = 1; i < n; i++) {
    if (dp[i] == 0) continue;
    dp[i] += dp[i - 1];
    ans += dp[i];
  }
  cout << ans << '\n';
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


