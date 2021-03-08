
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  if (max(x, y) != max(y, z) or max(z, x) != max(z, y)) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    cout << min({x, y, z}) << ' ' << min({x, y, z}) << ' ' << max({x, y, z}) << '\n';
  }
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


