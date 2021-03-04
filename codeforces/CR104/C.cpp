#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 0 << '\n';
    return;
  }
  if (n & 1) {
    for (int i = 0; i < (n * (n - 1)) / 2; i++) {
      cout << (i & 1 ? 1 : -1) << ' ';
    }
  } else {
    for (int i = 1; i < n; i++) {
      int curr = 1;
      for (int j = i + 1; j <= n; j++) {
        if (j == i + 1 and i & 1) {
          cout << 0 << ' ';
        } else {
          cout << (curr & 1 ? -1 : 1) << ' ';
          curr++;
        }
      }
    }
  }
  cout << '\n';
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


