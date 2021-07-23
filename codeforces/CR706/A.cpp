
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  bool possible = (2 * k == n ? false : true);
  for (int i = 0; i < k; i++) {
    if (s[i] == s[n - i - 1]) continue; 
      possible = false;
  }
  cout << (possible ? "YES" : "NO") << '\n';
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


