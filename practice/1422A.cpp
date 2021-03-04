
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max({a, b, c}) << '\n';
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


