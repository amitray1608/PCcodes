
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  int N = 2 * n - 1;
  string s; cin >> s;
//  for (int i = 0; i < 2 * n - 1; i += 2) {
//    cout << s[i];
//  }
  
  auto check = [&](int a[]) {
    for (int i = 0; i < n; i++) {
      bool ok = false;
      for (int j = 0; j < n; j++) {
        if (s[i + j] - '0' == a[j]) {
          ok = true;
          break;
        }
      }
      if (!ok) return false;
    }
    return true;
  };

  while (true) {
    int a[n];
    for (int i = 0; i < n; i++) {
      a[i] = rand() % 2;
    }
    if (check(a)) {
      for (int i = 0; i < n; i++) {
        cout << a[i];
      }
      break;
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


