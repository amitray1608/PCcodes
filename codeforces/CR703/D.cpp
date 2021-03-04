#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int res;

  auto check = [&](int x) {
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (a[i] < x) b[i] = -1;
      else b[i] = 1;
      b[i] += b[i - 1];
    }
    int mini = INT_MAX;
    for (int i = k; i <= n; i++) {
      mini = min(mini, b[i - k]);
      if (b[i] - mini > 0) {
        return true;
      }
    }
    return false;
  };

  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      res = mid; 
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << res << '\n';
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


