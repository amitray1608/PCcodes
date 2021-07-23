
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> adj[n], rev[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    rev[v].push_back(u);
    adj[u].push_back(v);
  }
  vector<int> order, vis(n, 0), parent(n), res(n, 0);
  iota(parent.begin(), parent.end(), 0);

  function<void(int)> topo = [&](int s) {
    vis[s] = true;
    for (int i : adj[s]) {
      if (!vis[i]) topo(i);
    }
    order.push_back(s);
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) topo(i);
  }
  reverse(order.begin(), order.end());
  
  int maxi = 0;
  vis.assign(n, false);
  vector <int> comp;
  function<void(int)> dfs = [&](int s) {
    vis[s] = true;
    comp.push_back(s);
    for (int i : rev[s]) {
      if (!vis[i]) dfs(i);
    }
  };
  
  vector<int> root_node;
  for (int i : order) {
    if (!vis[i]) {
      dfs(i);
      long long sum = 0;
      int root = comp.front();
      for (int j : comp) {
        parent[j] = root;
        sum += a[j];
      }
      for (int j : comp) {
        res[i] = sum;
      }     
      root_node.push_back(root);
      comp.clear();
    }
  }

  vector<vector<int>> new_adj(n);
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      int v = parent[i];
      int u = parent[j];
      if (u != v) 
        new_adj[u].push_back(v);
    }
  }
  
  vector<int> dp(n, 0);

  function <int(int)> recc = [&](int s) {
    if (dp[s]) return dp[s];
    int curr = 0;
    for (int v : new_adj[s]) {
      curr = max(curr, recc(v));
    }
    return dp[s] = res[s] + curr;
  };

  maxi = 0;
  for (int i : root_node) {
    maxi = max(maxi, recc(i));
  }
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

