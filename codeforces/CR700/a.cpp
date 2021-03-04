
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size(), turn = 1;
  for (int i = 0; i < n; i++) {
    if (turn&1) {
      if (s[i] == 'a') s[i] = 'b';
      else s[i] = 'a';
    } else {
      if (s[i] == 'z') s[i] = 'y';
      else s[i] = 'z';
    }
    turn ^= 1;
  }
  cout << s << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


