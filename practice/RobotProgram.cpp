
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  int ans = x + y;
  if (x != y)
    ans += max(x, y) - min(y, x) - 1;
  cout << max(ans, 0) << '\n';
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


