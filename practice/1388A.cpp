
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n < 31) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    if (n == 31) {
      cout << 6 << ' ' << 14 << ' ' << 10 << ' ' << 1 << '\n';
    } else {
      vector<int> a({6, 10, 14, 15, 21, 35});
      for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
          for (int k = j + 1; k < 6; k++) {
            int left = n - a[i] - a[j] - a[k];
            bool ok = true;
            for (int l = 0; l < 6; l++) {
              if (left == a[l]) ok = false;
            }
            if (ok) {
              cout << a[i] << ' ' << a[j] << ' ' << a[k] << ' ' << left << '\n';
              return;
            }
          }
        }
      }
    }
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


