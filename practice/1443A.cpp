
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int i = 0, k = 2 * (n + 1);
  while (i < n) {
    cout << k << ' ';
    i++;
    k += 2;
  }
  cout << '\n';
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


