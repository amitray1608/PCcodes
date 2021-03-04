#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int maxi = 0;
  int sum = 0, j = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum <= s) {
      maxi = max(maxi, i - j + 1);
    } else {
      while (j <= i) {
        sum -= a[j++];
        if (sum <= s) break;
      }
      maxi = max(maxi, i - j + 1);
    }
  }
  cout << maxi << '\n';
}

signed main() {
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


