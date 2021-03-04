
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')') count++;
    else break;
  }
  bool ok = count > (n - count); 
  cout << (ok ? "YES" : "NO") << '\n';
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


