#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a;
  a.push_back(0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  } 
  a.push_back(m);
  int ans = 0;
  n += 1;
  vector<int> pre(n + 1, 0);
  for (int i = n; i > 0; i--) {
    if (i & 1) {
      ans += a[i] - a[i - 1];
      pre[i - 1] -= a[i] - a[i - 1];
    } else {
      pre[i - 1] += a[i] - a[i - 1]; 
    }
    pre[i - 1] += pre[i];
  }
  int maxi = ans;
  for (int i = 1; i < n; i++) {
    maxi = max(maxi, ans + pre[i] - 1);
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


