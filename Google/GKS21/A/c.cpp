
#include <bits/stdc++.h>

using namespace std;
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
#define int int64_t

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a;
  a.resize(n, vector<int>(m, 0));
  set<array<int, 3>, greater<array<int, 3>>> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      st.insert({a[i][j], i, j});
    }
  }
  int mini = 0; 
  while (!st.empty()) {
    auto x = *st.begin();
    int i = x[1], j = x[2];
    int maxi = x[0];
    st.erase(st.begin());
    for (int k = 0; k < 4; k++) {
      int newi = i + dx[k];
      int newj = j + dy[k];
      if (newi >= 0 and newi < n and newj >= 0 and newj < m) {
        if (a[i][j] - a[newi][newj] > 1) {
          mini += a[i][j] - a[newi][newj] - 1;
          st.erase({a[newi][newj], newi, newj});
          a[newi][newj] = a[i][j] - 1;
          st.insert({a[newi][newj], newi, newj});
        }
      }
    }
  }
  cout << mini << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


