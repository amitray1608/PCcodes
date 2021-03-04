#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  int n = (int)s.size();
  int up = 0, down = 0;
  int left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') up++;
    else if (s[i] == 'D') down++;
    else if (s[i] == 'L') left++;
    else right++;
  }
  bool ok = false;
  if (x <= 0 and y <= 0) {
    ok = (left >= abs(x) and down >= abs(y));
  } else if (x <= 0 and y >= 0) {
    ok = (left >= abs(x) and up >= y);
  } else if (x >= 0 and y <= 0) {
    ok = (right >= x and down >= abs(y));
  } else if (x >= 0 and y >= 0) {
    ok = (right >= x and up >= y);
  }
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


