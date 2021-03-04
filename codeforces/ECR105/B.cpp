
#include <bits/stdc++.h>

using namespace std;

int n, u, r, d, l;

void solve() {
  cin >> n >> u >> r >> d >> l;
  
  auto check = [&](int mask, int U, int R, int D, int L) {
    if (mask & 1) {
      U--;
      R--;
    }
    if (mask & 2) {
      U--;
      L--;
    }
    if (mask & 4) {
      D--;
      R--;
    }
    if (mask & 8) {
      D--;
      L--;
    }
    return 0 <= min({U, R, D, L}) and max({U, R, D, L}) <= n - 2;
  };

  bool ok = false;
  for (int mask = 0; mask < (1 << 4); mask++) { 
    if (check(mask, u, r, d, l)) {
      ok = true;
      break;
    }
  }
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


