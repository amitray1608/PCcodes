#include<bits/stdc++.h>

using namespace std;

int n, m;
int start, last;
vector<vector<int>> adj;
vector<int> par, vis;

bool dfs(int u) {
  vis[u] = 1;
  for(auto v : adj[u]) {
    if(vis[v] == 0) {
      par[v] = u;
      if(dfs(v)) return true;
    } else if(vis[v] == 1) {
      start = v, last = u;
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
  }
  
  start = -1, last = -1;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      if(dfs(i)) break;
    }
  }

  if(start == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> ans;
    ans.push_back(start);
    for(int i = last; i != start; i = par[i])
      ans.push_back(i);
    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i  : ans) cout << i+1 << ' ';
    cout << '\n';
  }

  return 0;
}
