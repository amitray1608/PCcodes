
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  bool ok = true, prev = false;
  for (int i = 0; i < (int)s.size() - 1; i++) {
    if (s[i] == '1' and s[i + 1] == '1') {
      prev = true;
    }
    if (prev and (s[i] == '0' and s[i + 1] == '0')) {
      ok = false;
      break;
    }
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


