
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
  } else if (~ n & 1) {
    cout << (n == 2 ? 1 : 2) << '\n';
  } else {
    cout << (n == 3 ? 2 : 3) << '\n';  
  }
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


