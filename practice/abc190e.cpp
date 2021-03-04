
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int inf = 1e9;
const int maxn = 18;
int n, m, k;
vector<vector<int>> adj, dis;
vector<int> c;
int pos = 0;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void dijkstra(int s) {
  vector<int> dist(n, inf);
  dist[s] = 0;
  minpq<pair<int, int>> q;
  q.push({0, s});
  while (!q.empty()) {
    int w, u;
    tie(w, u) = q.top();
    q.pop();
    if (w > dist[u]) continue;
    for (auto i : adj[u]) {
      if (dist[i] > dist[u] + 1) {
        dist[i] = dist[u] + 1;
        q.push({dist[i], i});
      }
    }
  }
  dis.push_back(dist);
}

void solve() {
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  map<int, int> mp;
  cin >> k;
  c.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i]; c[i]--;
    mp[i] = c[i];
    dijkstra(c[i]);
  }
  
//  for (auto i : dis) {
//    for (auto j : i) cout << j << ' ';
//    cout << '\n';
//  }
  
  int dp[k][(1 << k)];
  for (int i = 0; i < k; i++) 
    for (int j = 0; j < (1 << k); j++) dp[i][j] = inf;
  
  for (int i = 0; i < k; i++) dp[i][(1 << i)] = 0;
  for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 0; i < k; i++) {
      if (mask & (1 << i) and mask != (1 << i)) {
        for (int j = 0; j < k; j++) {
          if (i == j) continue;
          dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + dis[i][mp[j]]);
        }
      }
    }
  }
  int mini = inf;
  for (int i = 0; i < k; i++) 
    mini = min(mini, dp[i][(1 << k) - 1]);
  cout << (mini >= inf ? -1 : mini + 1) << '\n';
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


