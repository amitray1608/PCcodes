#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> order;

bool dfs(int u) {
  vis[u] = 1;
  for(int i : adj[u])
    if(vis[i] == 1 or !vis[i] && dfs(i)) return false;
  vis[u] = 2;
  order.push_back(u);
  return true;
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, 0);
  vector<int> ind(n, 0);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    ind[v]++;
  }
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      if(!dfs(i)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  reverse(order.begin(), order.end());
  for(int i : order) cout << i + 1 << ' ';
  cout << '\n';
  return 0;
}
