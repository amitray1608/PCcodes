#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int N = ((n / 100) * 100) + 100;
  cout << N - n << '\n';
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


