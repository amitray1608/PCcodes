
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "1";
  int prev = 1 + s[0] - '0';
  for(int i = 1; i < n; i++) {
    int c = s[i] - '0';
    if(c == 0) {
      if(prev == 2) ans += '1', prev = 1;
      else if(prev == 1) ans += '0', prev = 0;
      else ans += '1', prev = 1;
    } else {
      if(prev == 2) ans += '0', prev = 1;
      else if(prev == 1) ans += '1', prev = 2;
      else ans += '1', prev = 2;
    }
  }
  cout << ans << '\n';
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

