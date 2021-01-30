#include <bits/stdc++.h>

using namespace std;

void solve() {
  int q, d;
  cin >> q >> d;
  
  auto check = [&](int x ) {
    while (x) {
      if (x % 10 == d) return true;
      x /= 10;
    }
    return false;
  };

  while (q--) {
    int x;
    cin >> x;
    bool ok = false;
    while (x >= 2 * d) {
      if (check(x)) {
        ok = true;
        break;
      } 
      x -= d;
    }
    if(check(x)) ok = true;
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


