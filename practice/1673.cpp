
#include "bits/stdc++.h"

using namespace std;
#define int int64_t

int n, m;
vector<vector<array<int, 2>>> adj;
vector<int> dis, vis, color, parent;
bool ok = false;
int khatam, start;

bool cycle(int s) {
  color[s] = 1;
  for (auto [v, c] : adj[s]) {
    if (color[v] == 0) {
      parent[v] = s;
      if (cycle(v)) return true;
    } else if (color[v] == 1) {
      khatam = s;
      start = v;
      return true;
    }
  }
  color[s] = 2;
  return false;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> n >> m;
  adj.resize(n);
  color.resize(n, 0);
  dis.resize(n, LONG_MIN);
  vis.resize(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
  }
  parent.resize(n, -1);
  bool iscycle = false;
  for (int i = 0; i < n; i++) {
    if (!color[i] and cycle(i)) {
      iscycle = true;
      break;
    }
  }
  queue<int> q;
  q.push(0);
  vis[0] = true;
  dis[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, c] : adj[u]) {
      if (dis[v] < dis[u] + c) {
        q.push(v);
        dis[v] = dis[u] + c;
      }
    }
  }
  if (dis[n - 1] == LONG_MIN) {
    cout << -1 << '\n';
  } else if (!cycle)
  return 0;
} //Hajimemashite
