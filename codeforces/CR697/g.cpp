#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int>a(n);
  for(int &i : a) cin >> i;
  int maxi = *max_element(a.begin(), a.end());
  std::vector<int> count(maxi + 1);
  for(int &i : a) count[i]++;
  vector<int> dp(maxi + 1);
  for (int i = 1; i <= maxi; ++i) {
    dp[i] += count[i];
    for (int j = i + i; j <= maxi; j += i) {
      dp[j] = max(dp[j], dp[i]);
    }
  }
  cout << n - *max_element(dp.begin(), dp.end()) << '\n';
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

