
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a;
  int x, y, maxi = 0;
  a.resize(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      maxi = max(maxi, a[i][j]);
    }
  }

  int mini = 0;
  vector<vector<int>> vis(n, vector<int> (m, 0));
  vector<vector<int>> dp(n, vector<int> (m, 0));

  function<void()> recc = [&]() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == maxi)
          q.push({i, j});
      }
    }
    while (!q.empty()) {
      auto x = q.front();
      int i = x.first;
      int j = x.second;
      q.pop();
      for (int k = 0; k < 4; k++) {
        int newi = i + dx[k];
        int newj = j + dy[k];
        if (newi >= 0 and newi < n and newj >= 0 and newj < m) {
          if (a[i][j] - a[newi][newj] > 1) {
            mini += a[i][j] - a[newi][newj] - 1;
            a[newi][newj] = a[i][j] - 1;
            q.push({newi, newj});
          }
        }
      }    
    }
  };

  recc();
  cout << (mini) << '\n';
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


