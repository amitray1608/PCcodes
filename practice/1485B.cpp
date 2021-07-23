
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, q, k;
  cin >> n >> q >> k;
  
  vector<int> a(n), dp(n, 0);
  for (int &i : a) {
    cin >> i;
  }
  dp[0] = a[0] - 1;
  for (int i = 1; i < n; i++) {
    dp[i] = a[i]  + dp[i - 1] - 1;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans = dp[r] - (l == 0 ? 0 : dp[l - 1]);
    cout << ans << '\n';
  }
  return 0;
} //Hajimemashite

