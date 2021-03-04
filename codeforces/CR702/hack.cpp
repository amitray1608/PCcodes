#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  freopen("inp.txt", "w", stdin);
  ll maxi = 1e12;
  cout << 100 << '\n';
  for (int i = 0; i < 100; i++) {
    cout << maxi - i << '\n';
  }
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


