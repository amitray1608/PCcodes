
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string x = to_string(n);
  int dig = (int)x.size();
  int ans = ((n % 10) * 10);
  ans -= (10 - (dig * (dig + 1) / 2));
  cout << ans << '\n';
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


