
#include <bits/stdc++.h>

using namespace std;
//#define int int64_t

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int inf = (1e17);

void dijkstra(int S) {
  minpq<array<int, 4>> Q;
  fill(dist.begin(), dist.end(), inf);
  Q.push({0, S, 0, 0});
  dist[S] = 0;
  while(!Q.empty()){
    auto [c, u, pmin, pmax] = Q.top();
    Q.pop();
    if(dist[u] < c){
      continue;
    }
    for(auto i : adj[u]){
      int w = i.second;
      int vv = i.first;
      int req = min((pmin - w), (pmax - w));
      if(dist[vv] > dist[u] + req){
        dist[vv] = (dist[u] + req);
        Q.push({dist[vv], vv, dist[vv], max(pmax, dist[vv])});
      }
    }
  }
}

int times = 0;
void dfs(int u) {
  if (u == n - 1)
    times++;
  if (times == 100) return;
  for (auto [v, c] : adj[u]) {
    if (dist[v] > dist[u] + (c - dist[u])) {
      dist[v] = dist[u] + (c - dist[u]);
      dfs(v);
    }
  }
}

signed main() {
    cin >> n >> m;
    adj.resize(n);
    dist.resize(n, 1000000000);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dist[0] = 0;
    dfs(0);
//    dijkstra(0);
    /*
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto [v, c] : adj[u]) {
        if (dist[v] > dist[u] + (c - dist[u])) {
            dist[v] = dist[u] + (c - dist[u]);
            q.push(v);
        }
      }
    }
    */
    if (dist[n - 1] >= inf) {
      cout << "NOT POSSIBLE" << '\n';
    } else {
      cout << dist[n - 1] << '\n';
    }
    return 0;
}


vector<int> solve(int x, vector<int> arr, vector<int> query_value) {
  vector<int> pos;
  int n = (int)arr.size();
  for (int i = 0; i < n; i++) {
    if (x == arr[i]) pos.push_back(i + 1);
  }
  vector<int> res;
  int q = query_value.size();
  for (int i = 0; i < q; i++) {
    int k = query_value[i];
    if (k > pos.size()) res.push_back(-1);
    else res.push_back(pos[k - 1]);
  }
  return res;
}
