
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  int mini = INT_MAX;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a.push_back({u, v});
    mini = min(mini, u + v);
  }
  sort (a.begin(), a.end(),
      [](const auto x, const auto y) {
        if (x.first == y.first) 
          return x.second < y.second;
        return x.first < y.first;
      });

  int smaxi = INT_MAX;
  for (int i = 0; i < n; i++) {
    smaxi = a[i].first;
    int fmaxi = INT_MAX;
    for (int j = i + 1; j < n; j++) {
      fmaxi = min(fmaxi, a[j].second);
    }
    if (max(smaxi, fmaxi) <= mini) {
      cout << max(smaxi, fmaxi) << '\n';
      return;
    }
  }
  cout << mini << '\n';
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


