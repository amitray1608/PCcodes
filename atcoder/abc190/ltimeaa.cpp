#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  bool ok = false;
  if (a + b == c or b + c == a or c + a == b)
    ok = true;
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


