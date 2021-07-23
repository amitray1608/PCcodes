
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e18;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  while (true) {
    int n, m, k;
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    int s, d; cin >> s >> d;
    k = 2;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      adj[u].push_back({v, c});
    }
    vector<vector<int>> dist(n, vector<int>(k, inf));
    minpq<array<int, 2>> pq;
    pq.push({0, s}); 
    dist[s][0] = 0;
    while (!pq.empty()) {
      auto [c, u] = pq.top();
      pq.pop();
      if (dist[u][k - 1] < c) continue;
      for (auto [v, w] : adj[u]) {
        if (c + w < dist[v][k - 1]) {
          dist[v][k - 1] = c + w;
          pq.push({dist[v][k - 1],v});
          sort(dist[v].begin(), dist[v].end());
        }
      }
    }
    cout << (dist[d][1] == inf ? -1 : dist[d][1]) << '\n';
  }
  return 0;
} //Hajimemashite

