
#include <bits/stdc++.h>

using namespace std;

void solve() {
  cout << fixed << setprecision(15);
  double a, b;
  cin >> a >> b;
  double x = a - b;
  double ans = x / a * 100.0;
  cout << ans << '\n';
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


