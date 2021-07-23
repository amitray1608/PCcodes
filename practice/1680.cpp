
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  vector<int> dist(n, 0), parent(n), vis(n, 0), flag(n, 0);
  flag[n - 1] = true;
  iota(parent.begin(), parent.end(), 0);
  function<int(int)> dfs = [&](int s) {
    vis[s] = true;
    for (int i : adj[s]) {
      if (!vis[i])
        dfs(i);
      flag[s] |= flag[i];
      if ((dist[s] < dist[i] + 1) and (flag[i])) {
        parent[i] = s;
        dist[s] = dist[i] + 1;
      }
    }
    return 0;
  };

//  priority_queue<array<int, 2>> q;
//  q.push({0, 0});
//  dist[0] = 0;
//  while (!q.empty()) {
//    auto [d, u] = q.top();
//    q.pop();
//    if (dist[u] > d) continue;
//    for (int v : adj[u]) {
//      if (dist[v] < dist[u] + 1) {
//        parent[v] = u;
//        dist[v] = dist[u] + 1;
//        q.push({dist[v], v});
//      }
//    }
//  }
//
  dfs(0);
  if (dist[n - 1] == -1) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    vector<int> res;
    for (int i = n - 1; i != parent[i]; i = parent[i]) {
      res.push_back(i);
    }
    res.push_back(0);
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int i : res) cout << i + 1 << ' ';
    cout << '\n';
  } 
  return 0;
} //Hajimemashite

