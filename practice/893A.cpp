
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  bool ok = true;
  int spec = 3, winner = a[0], loser = (a[0] == 1 ? 2 : 1);
  for (int i = 0; i < n; i++) {
    if (!i) {
      if (a[i] == 3) {
      ok = false;
      break;
      }
      continue;
    }
    if (a[i] == winner) {
      if (a[i] == 3) {
        
      }
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


