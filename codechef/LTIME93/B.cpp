
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int f[26] = {0};
  int timeseven = 0;
  for (char c : s) {
    f[c - 'a']++;
  }
  int odd = 0, even = 0, one = 0;
  for (int i = 0; i < 26; i++) {
    if (f[i] == 1) one++;
    if (f[i] & 1) {
      odd++;
      if (f[i] > 3) {
        timeseven += (f[i] - 3) / 2;
      }
    } else  even++, timeseven += f[i] / 2;
  }
  bool ok = (one <= timeseven);
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


