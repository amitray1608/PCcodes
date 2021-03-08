
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;
  if (l * 2 <= r) {
    cout << l << ' ' << l * 2 << '\n';
  } else {
    cout << -1 << ' ' << -1 << '\n';
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


