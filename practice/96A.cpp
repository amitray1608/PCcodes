
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int maxi = 0, onesum = 0, twosum = 0;
  for (char c : s) {
    if (c == '1') {
      onesum++;
      twosum = 0;
    } else {
      twosum++;
      onesum = 0;
    }
    maxi = max({maxi, onesum, twosum});
  }
  cout << (maxi >= 7 ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //kcout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


