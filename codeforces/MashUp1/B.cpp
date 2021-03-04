#include <bits/stdc++.h>

using namespace std;
using ld = long double;

void solve() {
  ld x, y;
  cin >> x >> y;
  ld logx = y * log(x);
  ld logy = x * log(y);
  if (logx > logy) {
    cout << ">" << '\n';
  } else if (logy > logx) {
    cout << "<" << '\n';
  }  else {
    cout << "=" << '\n';
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


