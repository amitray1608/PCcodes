
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int count = 0;
  int B = 0, b = 0;
  for (char c : s) {
    if (c == ']' and B > 0) {
      B--;
      count++;
    } else if (c == '[') {
      B++;
    } else if (c == '(') {
      b++;
    } else if (c == ')' and b > 0) {
      b--;
      count++;
    }
  }
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


