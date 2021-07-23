
#include<bits/stdc++.h>

using namespace std;

#define int int64_t
int n, m, T, C;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int inf = (int) (1e18);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k = 2;
  cin >> n >> m >> T >> C;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, c = C;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  vector<vector<int>> dist(n, vector<int>(k, inf));
  minpq<array<int, 2>> pq;
  pq.push({0, 0});
  dist[0][0] = 0;
  while (!pq.empty()) {
    int c = pq.top()[0];
    int u = pq.top()[1];
    pq.pop();
    if (dist[u][k - 1] < c) continue;
    for (auto i : adj[u]) {
      int v = i.first;
      int w;
      if (v == n - 1) w = dist[u][k - 1] + C;
      else
        w = ((dist[u][k - 1] + C + (2 * T) - 1) / (2 * T)) * (2 * T);  
      if (w < dist[v][k - 1]) {
        dist[v][k - 1] = w;
        pq.push({dist[v][k - 1],v});
        sort(dist[v].begin(), dist[v].end());
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i][0] << ' ' << dist[i][1] << '\n';
  }
  int w = dist[n - 1][1];
  cout << (w == inf ? -1 : w) << '\n';
  return 0;
} //Hajimemashite

