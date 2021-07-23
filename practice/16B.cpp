
#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> a;

void solve() {
  int n, m;
  cin >> n >> m;
  a.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  sort (a.begin(), a.end(), 
      [](const auto x, const auto y) {
        return x[1] > y[1];
      });
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    ans += min(n, a[i][0]) * a[i][1];
    n -= a[i][0];
    n = max(0, n);
  }
  cout << ans << '\n';
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





