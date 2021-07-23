
//Sleepy as Hell.
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> res(n, 1);
  for (int i = 1; i < n; i++) {
    if (s[i - 1] < s[i]) {
      res[i] += res[i - 1];
    }
  }
  for (int i = 0; i < n; i++) 
    cout << res[i] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


