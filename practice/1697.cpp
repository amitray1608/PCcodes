
#include<bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<vector<int>> adj;
vector<bool> vis, restack;
vector<int> order, ind;
 
void dfs(int u) {
  vis[u] = true;
  for(int i : adj[u])
    if(!vis[i]) dfs(i);
  order.push_back(u);
}

bool check(int s) {
  if (!vis[s]) {
    vis[s] = true;
    restack[s] = true;
    for (auto i : adj[s]) {
      if (!vis[i] and check(i))
        return true;
      else if (restack[i])
        return true;
    }
  }
  restack[s] = false;
  return false;
}

bool cycle() {
  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (check(i)) return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  restack.resize(n, false);
  vis.resize(n, false);
  ind.assign(n, 0);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    ind[v]++;
    adj[u].push_back(v);
  }
  bool flag = false;
  for(int i = 0; i < n; i++) {
    if(ind[i] == 0) flag = true;
    if(!vis[i])
      dfs(i);
  }
  reverse(order.begin(), order.end());
  if(!flag or cycle()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for(int i : order) cout << i + 1 << ' ';
  cout << '\n';
  return 0;
}
