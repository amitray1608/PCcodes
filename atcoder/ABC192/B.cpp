#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  bool ok = true;
  int n = (int)s.length();
  for (int i = 0; i < n; i++) {
    if (~i&1) {
      if (s[i] >= 'a' and s[i] <= 'z') continue;
      ok = false;
    } else {
      if (s[i] >= 'A' and s[i] <= 'Z') continue;
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
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


