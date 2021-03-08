
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  int diff = abs(a - b);
  int count = diff / 5;
  diff %= 5;
  count += diff / 2;
  count += diff % 2;
  cout << count << '\n';
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


