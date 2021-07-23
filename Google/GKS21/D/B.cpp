
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e18;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> a(n);  
  int m = inf, M = 0;
  for (auto &i : a) {
    cin >> i.first >> i.second;
    m = min(m, i.first);
    M = max(M, i.second);
  }
  vector<pair<int, int>> p;
  for (int i = m; i <= M; i++) {
    int cs = 0;
    for (auto j : a) {
      if (i > j.first and i < j.second) cs++;
    }
    p.push_back({i, cs});
  }
  sort(p.begin(), p.end(), [&](auto &x, auto &y) {
        return x.second > y.second;
        });
  int res = 0;
  for (int i = 0; i < c; i++) res += p[i].second + 1;
  cout << res << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }	
  return 0;
} //Hajimemashite

