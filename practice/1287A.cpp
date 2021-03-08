
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      pos = i;
      break;
    }
  }
  if (pos == -1 or pos == n - 1) {
    cout << 0 << '\n';
  } else {
    int count = 0, maxi = 0;
    for (int i = pos + 1; i < n; i++) {
      if (s[i] == 'A') {
        maxi = max(maxi, count);
        count = 0;
      } else {
        count++;
      }
    }
    maxi = max(maxi, count);
    cout << maxi << '\n';
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


