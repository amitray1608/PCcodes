
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    bool ok = false;
    for (int i = 0; i < l; i++)
      if (s[i] == s[l]) {
        ok = true;
        break;
      }
    for (int j = r + 1; j < n; j++) 
      if (s[j] == s[r]) {
        ok = true;
        break;
      }
    cout << (ok ? "YES" : "NO") << '\n';
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


