
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if(abs(a - b) < 3)  cout << "Yes" << '\n';
  else cout << "No" << '\n';
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

