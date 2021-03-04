#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  bool ok = true;
  if (s[0] != 'C' or s[1] != 'M' or s[2] != 'P')
    ok = false;
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


