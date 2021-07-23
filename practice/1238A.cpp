
#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long x, y;
  cin >> x >> y;
  bool ok = (x - y <= 1 ? false : true);
  cout << (ok ? "YES" : "NO") << '\n';
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


