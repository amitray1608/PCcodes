
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[i] > dp[j] + 1) continue;
      if (a[i] > a[j] and b[i] < b[j]) 
        dp[i] = max(dp[i], dp[j] + 1); 
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n'; 
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


