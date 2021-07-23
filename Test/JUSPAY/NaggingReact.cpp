
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int inf = 1e5;
int n, m;
map<int, int> mp, pm;
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
  parent.resize(n + 1);
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
  int N;
  cin >> N;
  n = N + N;
  int count = 0;
  vector<int> node;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    pm[count] = x;
    mp[x] = count++;
    node.push_back(x);
  }
  
  adj.resize(n + 1);
  cap.resize(n + 1, vector<int>(n + 1, 0));
  cp.resize(n + 1, vector<int>(n + 1, 0)); 
  cin >> m;
  vector<int> vis(n, 0);
  vector<array<int, 2>> edge;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edge.push_back({u, v});
  }
  int st,ed;
  cin >> st >> ed;
  st = mp[st];
  ed = mp[ed];
  for (int i = 0; i < N; i++) {
    if (i == st or i == ed) continue;
    adj[i + N].push_back(i);
    adj[i].push_back(i + N);
    cap[i][i + N] = 1;
    cp[i][i + N] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    u = edge[i][0];
    v = edge[i][1];
    u = mp[u];
    v = mp[v];
    if (u == st) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      cap[u][v] = inf;
      continue;
    }
    if ((u == ed and v == st) or (u == st and v == ed)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      cap[u][v] = inf;
      continue;
    }
    adj[u + N].push_back(v);
    adj[v].push_back(u + N);
    cap[u + N][v] = inf;
  }
  for (int i = 0; i < n; i++) {
    cp[i] = cap[i];
  }

  maxflow(st, ed);
  vector<array<int, 2>> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (parent[i] != -1 and parent[j] == -1 and cp[i][j]) {
        res.push_back({i, j});
      }
    }
  }
  if (res.size() == 0) {
    cout << -1 << '\n';
    return 0;
  } 
  for (auto i : res) {
    cout << pm[i[0]] << ' ';
  }
  cout << '\n';
  return 0;
} //Hajimemashite

