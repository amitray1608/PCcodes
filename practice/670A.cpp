
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int mini = (n / 7) * 2 + max(0, n % 7 - 5);
  int maxi = (n / 7) * 2 + min(2, n % 7);
  cout << mini << ' ' << maxi << '\n';
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


