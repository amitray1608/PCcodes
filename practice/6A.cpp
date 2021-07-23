
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a[4];
  for (int i = 0; i < 4; i++) 
    cin >> a[i];
  sort (a, a + 4);
  int ok = 0;
  for (int i = 3; i > 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      int sum = a[j] + a[j - 1];
      if (sum > a[i]) {
        cout << "TRIANGLE" << '\n';
        return;
      }
      if (sum == a[i])
        ok = 1;
    }
  }
  cout << (ok ? "SEGMENT" : "IMPOSSIBLE") << '\n';
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


