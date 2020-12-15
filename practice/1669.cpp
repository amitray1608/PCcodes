#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
int cycles = -1, cyclee = -1;
vector<int> par;

bool dfs(int u, int p) {
  vis[u] = 1;
  for(int v : adj[u]) {
    if(v == p) continue;
    if(vis[v] == 0) {
      par[v] = u; 
      if(dfs(v, u)) return true;
    } else if(vis[v] == 1) {
      cycles = v, cyclee = u;
      return true;
    }
  }
  vis[u] = 2;
  return false;
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, 0);
  par.resize(n, -1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < n; i++) 
    if(!vis[i]) {
      if(dfs(i, par[i])) break;
    }
  if(cycles == -1)
    cout << "IMPOSSIBLE" << endl;
  else {
    vector<int> ans;
    ans.push_back(cycles);
    for(int i = cyclee; i != cycles; i = par[i])
      ans.push_back(i);
    ans.push_back(cycles);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i + 1 << ' ';
    cout << endl;
  }
  return 0;
}
