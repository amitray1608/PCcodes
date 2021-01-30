#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  int ans = 0;
  x *= 100;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    ans++;
    double v, p;
    cin >> v >> p;
    total += (v * p);
    if  (total > x) {
      cout << ans << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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


