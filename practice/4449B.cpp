
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e18;

signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<array<int, 2>> dis(n);
  for (int i = 0; i < n; i++) {
    dis[i][0] = inf;
    dis[i][1] = 0;
  }
  
  minpq <array<int, 3>> pq;
  int count = 0;
  for (int i = 0; i < k; i++) {
    int v, w;
    cin >> v >> w;
    v--;
    pq.push({w, v, 1});
  }

  dis[0][0] = dis[0][1] = 0;
  pq.push({0, 0, 0});
  while (!pq.empty()) {
    auto [w, u, by] = pq.top();
    pq.pop();
    if (dis[u][1] ) {
      count += by;
      continue;
    }
    dis[u][1] = 1;
    for (auto i : adj[u]) {
      auto [v, c] = i;
      if (dis[v][0] > w + c) {
        dis[v][0] = w + c;
        pq.push({dis[v][0], v, 0});
      }
    }
  }
  cout << count << '\n';
  return 0;
} //Hajimemashite

