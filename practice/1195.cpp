
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e18;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
  }
  vector<array<int, 2>> dis(n); 
  for (int i = 0; i < n; i++) {
    dis[i][0] = inf;
    dis[i][1] = inf;
  }
  minpq<array<int, 3>> pq;
  dis[0][0] = 0;
  dis[0][1] = 0;
  pq.push({0, 0, 0});
  while (!pq.empty()) {
    auto [w, u, mx] = pq.top();
    pq.pop();
    if (u == n - 1 and mx) break;
    for (auto x: adj[u]) {
      auto [v, c] = x;
      if (dis[v][mx] > w + c) {
        dis[v][mx] = w + c;
        pq.push({dis[v][mx], v, mx});
      } 
      if (!mx) {
        if (dis[v][1] > w + c / 2) {
          dis[v][1] = w + c / 2;
          pq.push({dis[v][1], v, 1});
        }
      }
    }
  }
  cout << min(dis[n - 1][0], dis[n - 1][1]) << '\n';
  return 0;
} //Hajimemashite

