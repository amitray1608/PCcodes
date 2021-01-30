#include <bits/stdc++.h>

using namespace std;

void solve() {
 char a, b, c;
 cin >> a >> b >> c;
 if (a == b and b == c) cout << "Won" << '\n';
 else cout << "Lost" << '\n';
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


