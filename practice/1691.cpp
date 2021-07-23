
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> res, vis(n, false);
  set<int> cnt; 
  function<void(int, int)> dfs = [&](int s, int p) {
    vis[s] = true;
    cnt.insert(s);
    res.push_back(s);
    if (cnt.size() == n or res.size() == 1e6) return;
    for (auto i : adj[s]) {
      if (i == p) continue;
      dfs(i, s);
    }
  };
  dfs(0, -1);
  bool ok = true;
  for (int i : vis) {
    ok &= i;
  }
  if (!ok) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    for (auto i : res) {
      cout << i << ' ';
    } cout << '\n';
  }
  return 0;
} //Hajimemashite

