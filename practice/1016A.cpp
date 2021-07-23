
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> res(n, 0);
  int left = 0;
  for (int i = 0; i < n; i++) {
    left %= m;
    left += a[i];
    res[i] = left / m;
  }
  for (int i : res) 
    cout << i << ' ';
  cout << '\n';
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


