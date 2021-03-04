#include <bits/stdc++.h>

using namespace std;
#define int int64_t

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> adj[n];
  vector<int> type[k];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    type[--x].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vector<int>> dist(k, vector<int> (n, INT_MAX));
  for (int i = 0; i < k; i++) {
    queue<int> q;
    for (auto j : type[i]) {
      dist[i][j] = 0;
      q.push(j);
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist[i][v] > dist[i][u] + 1) {
          dist[i][v] = dist[i][u] + 1;
          q.push(v);
        }
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    vector<int> res;
    for (int j = 0; j < k; j++) {
      res.push_back(dist[j][i]);
    }
    sort(res.begin(), res.end());
    long long ans = 0LL;
    for (int j = 0; j < s; j++) {
      ans += res[j];
    }
    cout << ans << ' ';
  }
  cout << '\n';
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


