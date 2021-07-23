
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int inf = 1e10;
int n, m;
vector<vector<int>> adj, cap, cp;
vector<int> parent;

int bfs(int s, int t) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, inf});

  while (!q.empty()) {
    int u = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int v : adj[u]) {
      if (parent[v] == -1 and cap[u][v]) {
        parent[v] = u;
        int new_flow = min(flow, cap[u][v]);
        if (v == t) {
          return new_flow;
        }
        q.push({v, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  parent.resize(n);
  int new_flow;
  while ((new_flow = bfs(s, t))) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      cap[prev][cur] -= new_flow;
      cap[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  cap.resize(n, vector<int> (n, 0)); 
  cp.resize(n, vector<int> (n, 0));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] += 1;
    cap[v][u] += 1;
    cp[u][v] += 1;
    cp[v][u] += 1;
  }
  maxflow(0, n - 1);
  vector<array<int, 2>> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (parent[i] != -1 and parent[j] == -1 and cp[i][j]) {
        res.push_back({i, j});
      }
    }
  }
  cout << res.size() << '\n';
  for (auto i : res) {
    cout << i[0] + 1 <<  ' ' << i[1] + 1 << '\n';
  }
  return 0;
} //Hajimemashite

