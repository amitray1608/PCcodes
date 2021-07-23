
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int w, b;
  cin >> w >> b;
  int bk1 = min(k1, k2);
  int bk2 = abs(k1 - k2);
  bool ok = true;
  if (bk1 + bk2 / 2 < w) {
    ok = false;
  }
  bk1 = min(n - k1, n - k2);
  if (bk1 + bk2 / 2 < b) {
    ok = false;
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


