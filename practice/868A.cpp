
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> t(n);
  bool ok = false;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i][0] == s[0] and t[i][1] == s[1])
      ok = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (t[i][1] == s[0] and t[j][0] == s[1])
        ok = true;
      if (t[i][0] == s[1] and t[j][1] == s[0])
        ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
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


