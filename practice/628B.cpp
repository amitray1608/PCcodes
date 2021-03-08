
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  getline(cin, s);
  int n = (int)s.size();
  vector<ll> dp(n + 1, 0);
  if (s[0] == '4' or s[0] == '8' or s[0] == '0')
    dp[0] = 1;
  for (int i = 1; i < n; i++) {
    int curr = (int)(s[i - 1] - '0') * 10;
    curr += s[i] - '0';
    if (curr % 4 == 0) {
      dp[i] += dp[i - 1] + i;
    } else {
      dp[i] = dp[i - 1];
    }
    if ((curr % 10) % 4 == 0)
      dp[i]++;
  }
//  for (int i = 0; i < n; i++) 
//    cout << dp[i] << ' ';
//  cout << '\n';
  cout << dp[n - 1] << '\n';
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


