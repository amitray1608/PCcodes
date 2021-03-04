
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int mini = INT_MAX;
  int cost = 0;
  for (int i = 0; i < n; i++) {
    int a, p;
    cin >> a >> p;
    mini = min(mini, p);
    cost += a * mini;
  }
  cout << cost << '\n';
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


