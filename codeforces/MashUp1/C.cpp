#include <bits/stdc++.h>

using namespace std;
#define int int64_t
int inf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> sz(n), cost(n);
  for (int i = 0; i < n; i++) {
    cin >> sz[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  vector<int> dp1(n, inf);
  int mini = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (sz[j] < sz[i]) {
        mini = min(mini, dp1[j] + cost[i]);
        dp1[i] = min(dp1[i], cost[j] + cost[i]);
      }
    }
  } 
  if (mini >= inf) {
    cout << -1 << '\n';
  } else {
    cout << mini << '\n';
  }
}

signed main() {
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


