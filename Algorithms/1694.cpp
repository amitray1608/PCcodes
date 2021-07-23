
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int n, m;
vector<vector<int>> adj, cap;

int bfs (int s, int t, vector<int> &parent) {
  fill (parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INT_MAX});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && cap[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, cap[cur][next]);
        if (next == t) {
          return new_flow;
        }
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);
  int new_flow;
  while ((new_flow = bfs(s, t, parent))) {
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
  cap.resize(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] += c;
  }
  cout << maxflow(0, n - 1) << '\n';
  return 0;
} //Hajimemashite


