
#include<bits/stdc++.h>
 
using namespace std;
#define int int64_t
#define deb(x) cout << #x << " = " << x << endl;
 
int n, m;
vector<vector<int>> adj, rev;
vector<int> order, vis, parent, comp;

void topo(int s) {
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) topo(i);
  }
  order.push_back(s);
}

void dfs(int s) {
  vis[s] = true;
  comp.push_back(s);
  for (int i : rev[s]) {
    if (!vis[i]) dfs(i);
  }
}

void component(int s) {
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) {
      parent[i] = parent[s];
      dfs(i);
    }
  }
}

int nodeCount(int s, int count) {
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) count += nodeCount(i, count);
  }
  return count + 1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  rev.resize(n);
  parent.resize(n);
  iota(parent.begin(), parent.end(), 0);
  vector<int> in(n, 0), out(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    in[v]++;
    out[u]++;
    rev[v].push_back(u);
    adj[u].push_back(v);
  }

  // Checking for a simple initial cycle
  vis.resize(n, 0);
  int count = nodeCount(0, 0);
  vis.assign(n, 0);
  int count1 = nodeCount(n - 1, 0);
  if (count == count1 and count == n) {
    cout << 0 << '\n';
    return 0;
  }
 
  vis.assign(n, false); 
  for (int i = 0; i < n; i++) {
    if (!vis[i]) component(i);
  }
  //Getting topological order
  vis.assign(n, false); 
  for (int i = 0; i < n; i++) {
    if (!vis[i]) topo(i);
  }
  reverse(order.begin(), order.end());
 

  //Getting SCC and maintaining and starting and ending node
  //of each component
  vis.assign(n, false); 
  vector<int> root_node;
  for (int i : order) {
    if (!vis[i]) {
      dfs(i);
      int root = comp.front();
      for (int j : comp) {
        parent[j] = root;
      } 
      root_node.push_back(root);
      comp.clear();
    }
  }

  in.assign(n, 0);
  out.assign(n, 0);
  map<int, set<int>> new_adj;
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      int v = parent[i];
      int u = parent[j];
      if (u != v) { 
        new_adj[v].insert(u);
        in[u]++;
        out[v]++;
      }
    }
  }

  vector<array<int, 2>> nodes;
  for (auto i : new_adj) {
    int type = 0;
    int u = i.first;
    if (!in[u] and  !out[u]) type = 1;
    else if (in[u]) type = 2;
    else type = 3;
    nodes.push_back({u, type});
  }

  vector<array<int, 2>> res;
  for (int i = 1; i < (int)nodes.size(); i++) {
    auto [u, tp] = nodes[i];
    auto [v, tpp] = nodes[i - 1];
    if (tp == 1) {
       res.push_back({u, v});
       res.push_back({v, u});
    } else if (tp == 2) {
      res.push_back({u, v});
    } else {
      res.push_back({v, u});
    }
  }
  cout << res.size() << '\n';
  for (auto i : res) {
    cout << i[0] + 1 << ' ' << i[1] + 1 << '\n';
  } 
  return 0;
} //Hajimemashite

