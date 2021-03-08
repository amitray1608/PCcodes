
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> ones, zeros;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      ones.push_back(i);
    else
      zeros.push_back(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int x = r - l + 1;
    string t = s.substr(l, x);
    vector<int> pos = (t[0] == '0' ? zeros : ones);
    int m = (int)t.length();
    bool ok = false;
    for (int ii : pos) {
      if (ii == l) continue;
      int i = ii, j = 0;
      while (i < n and j < m) {
        if (s[i] == t[j])
          i++, j++;
        else i++;
      }
      if (j == m) {
        cout << "YES" << '\n';
        ok = true;
        break;
      }
    }
    if (ok) continue;
    for (int miss = l + 1; miss <= r; miss++) {
      int i = l, j = 0; 
      while (i < n and j < m) {
        if (i == miss) {
          i++;
          continue;
        }
        if (s[i] == t[j])
          i++, j++;
        else i++;
      }
      if (j == m) {
        cout << "YES" << '\n';
        ok = true;
        break;
      }
    }
    if (!ok)
      cout << "NO" << '\n';
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


