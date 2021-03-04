
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << abs(c - a) + abs(d - b) + ((b == d or a == c) ? 0 : 2) << '\n';
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


